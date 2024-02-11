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

/*
  拡張GCD
  不定方程式 a * x + b * y == gcd(a, b)
  の解を (x, y) に格納する
*/
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b * x;
  return d;
}
void solve() {
  ll x; int y; ll p; int q;
  cin >> x >> y >> p >> q;
  if(2*(x+y) == p+q) {
    if(q > x+y) cout << max(x, p) << endk;
    else cout << "infinity" << endk;
  } else {
    ll ans = longinf;
    rep(i, y) {
      rep(j, q) {
        ll n, m;
        ll a = 2*(x+y), b = p+q;
        ll g = __gcd(a, b);
        ll target = p+j-(x+i);
        if(abs(target) % g != 0) continue;
        extGCD(a, b, n, m);
        n *= target/g;
        m *= target/g;
        if(m > 0 || n < 0) {
          ll c = 0;
          if(m > 0) chmax(c, (m + a/g - 1) / (a/g));
          if(n < 0) chmax(c, (-n + b/g - 1) / (b/g));
          n += c*(b/g);
          m -= c*(a/g);
        }
        m = -m;
        assert(n >= 0 && m >= 0);
        ll c = min(n/(b/g), m/(a/g));
        n -= c*(b/g);
        m -= c*(a/g);
        chmin(ans, max(a*n+x+i, b*m+p+j));
        // if(y > 0) {
        //   assert(x <= 0);
        //   ll m = abs(x)/k+1;
        //   // ll m = (y+n-1)/n;
        //   x += m*k;
        //   y -= m*n;
        //   assert(x > 0);
        // }
        // y = -y;
      }
    }
    if(ans == longinf) cout << "infinity" << endk;
    else cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
