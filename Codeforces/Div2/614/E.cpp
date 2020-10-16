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
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<vector<int>> parent(n, vector<int>(n)); // 根がiのときのjの親
  vector<vector<int>> dist(n, vector<int>(n));
  vector<vector<int>> sub(n, vector<int>(n));
  int root = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> int {
    parent[root][cur] = par;
    dist[root][cur] = (par==-1 ? 0 : dist[root][par]+1);
    for(int ne: G[cur]) {
      if(ne != par) sub[root][cur] += dfs(dfs, ne, cur);
    }
    return sub[root][cur] += 1;
  };
  rep(i, n) dfs(dfs, root=i, -1);
  vector<vector<ll>> dp(n, vector<ll>(n));
  vector<vector<pair<int, int>>> d(n);
  rep(i, n) rep(j, n) if(i!=j) d[dist[i][j]].push_back({i, j});
  rep(i, n) {
    if(i) {
      for(auto [u, v]: d[i]) {
        chmax(dp[u][v],
              max(dp[u][parent[u][v]], dp[parent[v][u]][v]) + 1LL * sub[v][u] * sub[u][v]);
      }
    }
  }
  ll mx = 0;
  rep(i, n) rep(j, n) chmax(mx, dp[i][j]);
  cout << mx << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
