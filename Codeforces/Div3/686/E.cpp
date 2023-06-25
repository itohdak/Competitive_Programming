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
  rep(i, n) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> path;
  vector<int> curPath;
  vector<bool> inPath(n);
  vector<bool> vis(n);
  bool loop = false;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(loop) return;
    if(inPath[cur]) {
      loop = true;
      auto itr = find(all(path), cur);
      int sz = path.end() - itr;
      curPath = vector<int>(sz);
      copy(itr, path.end(), curPath.begin());
      return;
    }
    if(vis[cur]) return;
    vis[cur] = true;
    inPath[cur] = true;
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      if(loop) return;
    }
    inPath[cur] = false;
    path.pop_back();
  };
  dfs(dfs, 0, -1);
  set<int> inLoop(all(curPath));
  auto dfs2 = [&](auto dfs2, int cur, int par) -> int {
    int ret = 0;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      if(inLoop.count(ne)) continue;
      ret += dfs2(dfs2, ne, cur);
    }
    return ret+1;
  };
  ll sz = curPath.size();
  ll ans = 0;
  ans += sz * (sz-1); // in loop
  ans += (sz-1) * (n-sz) * 2; // in loop -> out loop
  for(auto i: inLoop) {
    ll cnt = dfs2(dfs2, i, -1);
    ans += cnt * (cnt-1) / 2 + (cnt-1) * (n-sz-cnt+1);
  }
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
