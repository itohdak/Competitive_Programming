#include "header.hpp"

int main() {
  int n; cin >> n;
  vector<vector<int>> G(n);
  vector<int> tpl;
  vector<bool> vis(n);
  auto dfs = [&](auto dfs, int cur) {
    if(vis[cur]) return;
    vis[cur] = true;
    for(int ne: G[cur]) dfs(dfs, ne);
    tpl.push_back(cur);
  };
  rep(i, n) dfs(dfs, i);
  reverse(all(tpl));
}

/* topological sort with loop detection */
int main2() {
  int n; cin >> n;
  vector<vector<int>> G(n);
  vector<int> tpl;
  vector<bool> seen(n), finished(n);
  auto dfs = [&](auto dfs, int cur, int par) -> bool {
    if(seen[cur] && !finished[cur]) return true;
    if(seen[cur] || finished[cur]) return false;
    seen[cur] = true;
    bool ret = false;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      ret |= dfs(dfs, ne, cur);
    }
    finished[cur] = true;
    tpl.push_back(cur);
    return ret;
  };
  bool ret = false;
  rep(i, n) ret |= dfs(dfs, i, -1);
  if(ret) {
    // loop detected
  } else {
    reverse(all(tpl));
  }
  return 0;
}
