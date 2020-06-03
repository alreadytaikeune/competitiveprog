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
#include <iomanip>

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

const double pi=acos(-1.0);
typedef long int int32;
typedef unsigned long int UL;
typedef long long int LL;
typedef unsigned long long int  ULL;
typedef string str;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<ULL> VULL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;

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
    int T=0; re(T);
    FOR(t, 0, T, 1){
        int N; re(N);
        if(N%2 == 1){
            double al=0, au=pi/N/2;
            double m=(au+al)/3;
            double m2=2*(au+al)/3;
            double x1=1./sin(pi/N/2.), y1=0.;
            double x2=0.5, y2=1./tan(pi/N/2.);
            double M1, M2;
            while(m-al > 1e-9){
                double nx1, ny1, nx2, ny2;
                double mx1, my1, mx2, my2;
                nx1 = cos(m)*x1 - sin(m)*y1;
                ny1 = sin(m)*x1 + cos(m)*y1;
                nx2 = cos(m)*x1 - sin(m)*y1;
                ny2 = sin(m)*x1 + cos(m)*y1;
                mx1 = cos(m2)*x1 - sin(m2)*y1;
                my1 = sin(m2)*x1 + cos(m2)*y1;
                mx2 = cos(m2)*x1 - sin(m2)*y1;
                my2 = sin(m2)*x1 + cos(m2)*y1;
                M1 = max(nx1, ny2);
                M2 = max(mx1, my2);
                if(M1 > M2){
                    al = m;
                }
                else{
                    au = m2;
                }
                m=(au+al)/3;
                m2=2*(au+al)/3;
                // ps(m, " ", m2);

            }
            cout << std::fixed << std::setprecision(10) << max(M1, M2) << endl;
        }
        else
            cout << std::fixed << std::setprecision(10) << 1./tan(pi/N/2.) << endl;
    }
    return 0;
}
