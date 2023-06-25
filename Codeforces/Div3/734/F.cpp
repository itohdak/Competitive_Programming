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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if(k == 2) {
    cout << n * (n-1) / 2 << endk;
    return;
  }
  auto count = [&](int root) -> ll {
    vector<vector<int>> depth(n, vector<int>(n));
    auto dfs = [&](auto dfs, int cur, int par, int dep) -> void {
      depth[cur][0]++;
      for(int ne: G[cur]) {
        if(ne == par) continue;
        dfs(dfs, ne, cur, dep+1);
        rep(i, n) if(i+1 < n) depth[cur][i+1] += depth[ne][i];
      }
    };
    dfs(dfs, root, -1, 0);
    ll ret = 0;
    REP(dep, 1, n) {
      vector<vector<ll>> dp(G[root].size()+1, vector<ll>(k+1));
      dp[0][0] = 1;
      rep(i, G[root].size()) {
        rep(j, k+1) {
          (dp[i+1][j] += dp[i][j]) %= mod;
          if(j+1 <= k) (dp[i+1][j+1] += dp[i][j] * depth[G[root][i]][dep-1]) %= mod;
        }
      }
      (ret += dp[G[root].size()][k]) %= mod;
    }
    return ret;
  };
  ll ans = 0;
  rep(i, n) (ans += count(i)) %= mod;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
