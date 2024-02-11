#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  ll x0, y0, xn2, yn2;
  cin >> x0 >> y0 >> xn2 >> yn2;
  ld COS = cos(2*M_PI/n), SIN = sin(2*M_PI/n);
  cout << fixed << setprecision(10)
       << (COS*(x0-xn2)-SIN*(y0-yn2)+(x0+xn2))/2 << ' '
       << (SIN*(x0-xn2)+COS*(y0-yn2)+(y0+yn2))/2
       << endk;
  return 0;
}
