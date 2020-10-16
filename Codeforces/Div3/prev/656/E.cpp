#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  vector<vector<pair<int, int>>> G2(n);
  int id = 0;
  rep(i, m) {
    int t, x, y; cin >> t >> x >> y;
    x--; y--;
    if(t) {
      G[x].push_back(y);
    } else {
      G2[x].push_back({y, id});
      G2[y].push_back({x, id});
      id++;
    }
  }
  vector<int> Tpl;
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
    Tpl.push_back(cur);
    return ret;
  };
  bool ret = false;
  rep(i, n) ret |= dfs(dfs, i, -1);
  if(ret) {
    cout << "NO\n";
  } else {
    reverse(all(Tpl));
    vector<bool> done(id);
    for(int cur: Tpl) {
      for(auto ele: G2[cur]) {
        int id = ele.second;
        int ne = ele.first;
        if(done[id]) continue;
        G[cur].push_back(ne);
        done[id] = true;
      }
    }
    cout << "YES\n";
    rep(i, n) for(int ne: G[i]) cout << i+1 << ' ' << ne+1 << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
