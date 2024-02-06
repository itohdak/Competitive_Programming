#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

using mint = modint998244353;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<ll> X(m), Y(m);
  set<pair<ll, ll>> st;
  rep(i, m) {
    cin >> X[i] >> Y[i];
    st.insert({X[i], Y[i]});
  }
  vector<pair<int, int>> D = {{a, b}, {c, d}, {e, f}};
  map<pair<int, int>, mint> dp;
  dp[{0, 0}] = 1;
  rep(i, n) {
    map<pair<int, int>, mint> next_dp;
    for(auto& [p, cnt]: dp) {
      auto& [x, y] = p;
      rep(k, 3) {
        ll nx = x + D[k].first, ny = y + D[k].second;
        if(st.count({nx, ny})) continue;
        next_dp[{nx, ny}] += cnt;
      }
    }
    dp = next_dp;
  }
  mint ans = 0;
  for(auto& [p, cnt]: dp) ans += cnt;
  cout << ans.val() << endk;
  return 0;
}
