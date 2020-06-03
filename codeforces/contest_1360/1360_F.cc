#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;


#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
#define TRAV(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MAX(x) *max_element(x)
#define MAXV(x) *max_element(ALL(x))
#define MIN(x) *min_element(x)
#define MINV(x) *min_element(ALL(x))

const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int UL;
typedef long long int LL;
typedef unsigned long long int  ULL;
typedef string str;

int sgn(LL a) { return (a>0)-(a<0); }
LL sq(LL a) { return a*a; }


// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class T> str ts(T v) { // containers with begin(), end()
    bool fst = 1; str res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += ts(x);
    }
    res += "}"; return res;
}

// PRINTS
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
    pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
    pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// READS
template<class T> void re(T& x) { cin >> x; }
template<class A> void re(vector<A>& x) { TRAV(a,x) re(a); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class I> void dgts(I i, VI& out){
    for(; i>0; i/=10) out.PB(i%10);
}

int strdiff(string s1, string s2, int i, int m){
    int out = 0;
    FOR(j, i, m, 1) out += (s1[j] != s2[j]);
    return out;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; re(T);
    FOR(t, 0, T, 1){
        int n=0, m=0; re(n); re(m);
        vector<string> v(n);
        FOR(i, 0, n, 1) re(v[i]);

        int start = -1;
        set<char> s;
        FOR(i, 0, m, 1){
            FOR(j, 0, n, 1) s.emplace(v[j][i]);
            if(s.size() > 1){
                start = i;
                break;
            }
            s.clear();
        }

        if(start == -1){
            ps(v[0]); continue;
        }

        bool sol = false;
        for(auto c : s){
            FOR(i, 0, n, 1){
                if(c != v[i][start]){
                    string cand = v[i].substr(0, start) + c + v[i].substr(start+1, m-start);
                    //ps("cadidate is", cand);
                    bool ok = true;
                    FOR(j, 0, n, 1){
                        int d = strdiff(cand, v[j], 0, m);
                        if(d > 1){
                            //ps("diff too big with ", v[j], d);
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        ps(cand);
                        sol=true;
                        break;
                    }
                }
            }
            if(sol)
                break;
        }
        if(!sol) ps(-1);

    }
    return 0;
}
