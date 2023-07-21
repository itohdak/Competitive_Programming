#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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

void solve() {
  int n; ll c;
  cin >> n >> c;
  vector<ll> S(n);
  ll s1 = 0, s2 = 0;
  rep(i, n) {
    cin >> S[i];
    s1 += S[i];
    s2 += S[i]*S[i];
  }
  auto bsearch = [&]() -> ll {
    auto test = [&](ll w) {
      if(4*w*w > longinf/n) return false;
      return 4*w*w*n + 4*w*s1 + s2 <= c;
    };
    ll ok = 0, ng = inf;
    while(ng-ok > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll ans = bsearch();
  // cout << c << ' ' << 4*ans*ans*n + 4*ans*s1 + s2 << ' ';
  cout << ans << endk;
  // ll A = 4*n, B = 4*s1, C = s2-c;
  // ll ans = (-B + (ll)(sqrtl(B*B-4*A*C))) / (2*A);
  // cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
