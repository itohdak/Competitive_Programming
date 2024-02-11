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

ll distance(ll x1, ll y1, ll x2, ll y2) {
  return abs(x1-x2) + abs(y1-y2);
}
int sign(ll x1, ll x2) {
  return (x1-x2)/abs(x1-x2);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  ll ans = 0;
  ans += distance(xb, yb, xc, yc);
  ll mn = LONG_LONG_MAX;
  if(yc-yb != 0) {
    ll x = xb;
    ll y = yb - sign(yc, yb);
    chmin(mn, distance(xa, ya, x, y));
  }
  if(xc-xb != 0) {
    ll x = xb - sign(xc, xb);
    ll y = yb;
    chmin(mn, distance(xa, ya, x, y));
  }
  ans += mn;
  ans += 2;
  if(xc == xb && !(xa == xb && sign(yc, yb) * sign(ya, yb) == 1)) {
    chmin(ans, distance(xb, yb, xc, yc) + distance(xa, ya, xb, yb-sign(yc, yb)));
  }
  if(yc == yb && !(ya == yb && sign(xc, xb) * sign(xa, xb) == 1)) {
    chmin(ans, distance(xb, yb, xc, yc) + distance(xa, ya, xb-sign(xc, xb), yb));
  }
  cout << ans << endk;
  return 0;
}
