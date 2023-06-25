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
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n), from(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    from[v].push_back(u);
  }
  vector<bool> ok(n, true);
  rep(i, n) {
    if(G[i].size() == 1 || from[i].size() == 1) ok[i] = false;
  }
  {
    vector<vector<int>> Gtmp(n);
    rep(i, n) {
      if(!ok[i]) continue;
      for(int ne: G[i]) {
        if(!ok[ne]) continue;
        Gtmp[i].push_back(ne);
      }
    }
    G = Gtmp;
  }
  vector<int> tpl;
  vector<bool> vis(n);
  auto dfs = [&](auto dfs, int cur) {
    if(vis[cur]) return;
    vis[cur] = true;
    for(int ne: G[cur]) dfs(dfs, ne);
    tpl.push_back(cur);
  };
  rep(i, n) if(ok[i]) dfs(dfs, i);
  reverse(all(tpl));
  vector<int> dp(n, 1);
  int ans = 1;
  for(int cur: tpl) {
    chmax(ans, dp[cur]);
    for(int ne: G[cur]) {
      chmax(dp[ne], dp[cur]+1);
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
