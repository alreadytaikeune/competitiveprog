#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>

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
#define RALL(cont) cont.rbegin(), cont.rend()
#define TRAVIT(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define TRAV(a,x) for (auto& a: x)
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

typedef long int int32;
typedef unsigned long int UL;
typedef long long int LL;
typedef unsigned long long int  ULL;
typedef string str;
typedef pair<int, int> PII;
typedef vector<int> VI;


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




int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; re(T);
    FOR(t, 0, T, 1){
        string s; cin >> s;
        VI cl(s.size(), 0);
        VI cr(s.size(), 0);
        int n = s.size();
        FOR(i, 0, s.size(), 1){
            cl[i] += s[i] - '0';
            if(i > 0)
                cl[i] += cl[i-1];
            cr[n-1-i] = s[n-1-i] - '0';
            if(i > 0)
                cr[n-1-i] += cr[n-i];
        }

        int m = 10000000;
        FOR(i, 0, n+1, 1){
            int tmp0 = 0;
            int tmp1 = 0;
            if(i > 0){
                tmp0 = cl[i-1];
                tmp1 = i - cl[i-1];
            }
            if(i < n){
                tmp0 += (n-i) - cr[i];
                tmp1 += cr[i];
            }

            if(tmp0 < m)
                m = tmp0;
            if(tmp1 < m)
                m = tmp1;
        }

        ps(m);

    }

    
    return 0;
}
