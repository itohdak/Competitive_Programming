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
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> G(n);
  rep(i, m) {
    int u, v, c; cin >> u >> v >> c;
    u--; v--; c--;
    G[u].push_back({v, c});
    G[v].push_back({u, c});
  }
  vector<bool> vis(n);
  vector<int> col(n, -1);
  auto dfs = [&](auto dfs, int cur) -> void {
    if(vis[cur]) return;
    vis[cur] = true;
    for(auto [ne, c]: G[cur]) {
      if(vis[ne]) continue;
      if(c == col[cur]) col[ne] = (c+1)%n;
      else col[ne] = c;
      dfs(dfs, ne);
    }
  };
  col[0] = 0;
  dfs(dfs, 0);
  rep(i, n) cout << col[i]+1 << endk;
  return 0;
}
