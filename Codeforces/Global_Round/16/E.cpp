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
  vector<bool> is_leaf(n, true);
  vector<int> n_child(n), n_child_leaf(n);
  vector<int> P(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    P[cur] = par;
    is_leaf[cur] = (par != -1 && G[cur].size() == 1);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      if(is_leaf[ne]) n_child_leaf[cur]++;
      n_child[cur]++;
    }
  };
  dfs(dfs, 0, -1);
  int ans = accumulate(all(is_leaf), 0);
  int cnt = -1;
  auto dfs2 = [&](auto dfs2, int cur, int par) -> void {
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs2(dfs2, ne, cur);
    }
    is_leaf[cur] = (n_child[cur] == 0);
    if(cur && n_child[cur] && n_child[cur] == n_child_leaf[cur]) {
      n_child[par]--;
      if(par == 0 || n_child[par]) cnt++;
      else {
        if(P[par] != -1) {
          n_child_leaf[P[par]]++;
        }
      }
    }
  };
  dfs2(dfs2, 0, -1);
  for(int ne: G[0]) {
    if(is_leaf[ne]) {
      cnt++;
      break;
    }
  }
  cout << ans-max(0, cnt) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
