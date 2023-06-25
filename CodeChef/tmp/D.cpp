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
  int t; cin >> t;
  while(t--) {
    ll n, m, x, y; cin >> n >> m >> x >> y;
    if(n == 1 || m == 1) {
      cout << x*(max(n, m)-1) << endk;
    } else {
      chmin(y, 2*x);
      ll x2 = min(x*2, y*2);
      cout << y*(min(n, m)-1)+x2*((max(n, m)-min(n, m))/2)+x*((max(n, m)-min(n, m))%2) << endk;
    }
  }
  return 0;
}
