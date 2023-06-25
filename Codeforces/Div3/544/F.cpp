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
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int deg = 0, root = -1;
  rep(i, n) {
    if(G[i].size() > deg) {
      deg = G[i].size();
      root = i;
    }
  }
  vector<bool> vis(n);
  vector<pair<int, int>> E;
  auto dfs = [&](auto dfs, int cur) -> void {
    vis[cur] = true;
    for(int ne: G[cur]) {
      if(vis[ne]) continue;
      E.push_back({cur, ne});
      dfs(dfs, ne);
    }
  };
  vis[root] = true;
  for(int ne: G[root]) {
    E.push_back({root, ne});
    vis[ne] = true;
  }
  for(int ne: G[root]) {
    dfs(dfs, ne);
  }
  // cout << E << endl;
  assert(E.size() == n-1);
  for(auto [u, v]: E) {
    cout << u+1 << ' ' << v+1 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
