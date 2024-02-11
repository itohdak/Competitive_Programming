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
  ll x, a, d, n; cin >> x >> a >> d >> n;
  ll mn = a, mx = a+(n-1)*d;
  if(d < 0) {
    swap(mn, mx);
    d = -d;
  }
  if(d == 0) {
    cout << abs(x-a) << endk;
  } else if(x > mx) {
    cout << x-mx << endk;
  } else if(x < mn) {
    cout << mn-x << endk;
  } else {
    ll m = (x-a)/d;
    ll ans = longinf;
    for(int i=-5; i<=5; i++) {
      ll tmp = a+d*(m+i);
      if(tmp < mn || tmp > mx) continue;
      chmin(ans, abs(x-tmp));
    }
    cout << ans << endk;
  }
  return 0;
}
