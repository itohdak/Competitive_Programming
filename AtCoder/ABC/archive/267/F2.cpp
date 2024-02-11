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
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int q; cin >> q;
  vector<vector<pair<int, int>>> Q(n);
  rep(i, q) {
    int u, k; cin >> u >> k;
    u--;
    Q[u].push_back({i, k});
  }

  vector<int> dist(n);
  vector<int> P(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    P[cur] = par;
    if(par != -1) dist[cur] = dist[par]+1;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
    }
  };
  dfs(dfs, 0, -1);
  int s = max_element(all(dist)) - begin(dist);
  dist = vector<int>(n);
  dfs(dfs, s, -1);
  int t = max_element(all(dist)) - begin(dist);

  vector<int> ans(q, -2);
  vector<int> path;
  auto dfs2 = [&](auto dfs2, int cur, int par) -> void {
    path.push_back(cur);
    for(auto [i, k]: Q[cur]) {
      // cout << path << ' ' << k << endk;
      if(path.size() > k) {
        ans[i] = path[path.size()-1-k];
      }
    }
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs2(dfs2, ne, cur);
    }
    path.pop_back();
  };
  dfs2(dfs2, s, -1);
  dfs2(dfs2, t, -1);
  rep(i, q) {
    cout << ans[i]+1 << endk;
  }
  return 0;
}
