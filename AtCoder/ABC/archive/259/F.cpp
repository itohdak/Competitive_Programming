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
  vector<int> D(n); rep(i, n) cin >> D[i];
  vector<vector<pair<int, int>>> G(n);
  rep(i, n-1) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  vector<vector<ll>> dp(n);
  rep(i, n) {
    dp[i] = vector<ll>(D[i]+1);
  }
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    ll sum = 0;
    vector<ll> diff;
    for(auto [ne, w]: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      sum += dp[ne][D[ne]];
      if(D[ne] > 0 && dp[ne][D[ne]-1] + w > dp[ne][D[ne]]) {
        diff.push_back(dp[ne][D[ne]-1] + w - dp[ne][D[ne]]);
      }
    }
    sort(all(diff), greater<ll>());
    vector<ll> cum(diff.size()+1);
    rep(i, diff.size()) cum[i+1] = cum[i] + diff[i];
    dp[cur][D[cur]] = sum + cum[min(D[cur], (int)cum.size()-1)];
    if(D[cur] > 0) dp[cur][D[cur]-1] = sum + cum[min(D[cur]-1, (int)cum.size()-1)];
  };
  dfs(dfs, 0, -1);
  // cout << dp << endk;
  cout << dp[0][D[0]] << endk;
  return 0;
}
