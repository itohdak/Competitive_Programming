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

vector<vector<int>> G;
vector<int> Tpl;
vector<bool> vis;

/* topological sort */
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}
// rep(i, N) dfs(i);
// reverse(all(Tpl));


/* topological sort with loop detection */
vector<bool> seen, finished;
bool dfs2(int cur, int par) {
  if(seen[cur] && !finished[cur]) return true;
  if(seen[cur] || finished[cur]) return false;
  seen[cur] = true;
  bool ret = false;
  for(int ne: G[cur]) {
    if(ne == par) continue;
    ret |= dfs2(ne, cur);
  }
  finished[cur] = true;
  Tpl.push_back(cur);
  return ret;
};
// bool ret = false;
// rep(i, n) ret |= dfs2(i, -1);
// if(ret) {
//   // loop
// } else {
//   reverse(all(Tpl));
// }
