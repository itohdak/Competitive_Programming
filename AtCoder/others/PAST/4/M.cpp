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

struct edge {
  int to;
  ll cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

class LCA {
public:
  int V, logV;
  vector<int> depth, len;
  vector<vector<int> > parent; // parent[i][v]: ノードvの(i+1)個上の親

  LCA(int V) {
    this->V = V;
    logV = 0;
    while(V > (1LL<<logV)) logV++;
    this->depth = vector<int>(V);
    this->len = vector<int>(V);
    this->parent = vector<vector<int> >(logV, vector<int>(V));
  }

  void init(int v, int par, int d, int l, vector<vector<edge>>& G) {
    depth[v] = d;       // rootからの深さ
    parent[0][v] = par; // 親
    len[v] = l;         // rootからの距離
    for(int i=0; i<(int)G[v].size(); i++) {
      int w = G[v][i].to;   // 子ノード
      int lc = G[v][i].cost; // 子ノードとの距離
      if(w == par) continue;
      init(w, v, d+1, lc + l, G);
    }
  }

  void build() {
    for(int k=0; k+1<logV; k++) {
      for(int v=0; v<V; v++) {
        if(parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  int query(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    for(int k=0; k<logV; k++) {
      if((depth[v] - depth[u]) >> k & 1)
        v = parent[k][v];
    }
    if(u == v) return u;

    for(int k=logV-1; k>=0; k--) {
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<vector<edge>> G(n);
  map<pair<int, int>, int> id;
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back({b, 1});
    G[b].push_back({a, 1});
    id[{min(a, b), max(a, b)}] = i;
  }
  LCA lca(n);
  lca.init(0, -1, 0, 0, G);
  lca.build();
  vector<int> col(n-1);
  vector<tuple<int, int, int>> Q(q);
  for(auto& [u, v, c]: Q) {
    cin >> u >> v >> c;
    u--; v--;
  }
  vector<int> in(n), out(n);
  int cnt = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    in[cur] = cnt++;
    for(auto [ne, _]: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
    }
    out[cur] = cnt++;
  };
  dfs(dfs, 0, -1);
  vector<int> next(n);
  rep(i, n) next[i] = lca.parent[0][i];
  rrep(i, q) {
    auto [u, v, c] = Q[i];
    int w = lca.query(u, v);
    auto setColor = [&](int from, int to) {
      int cur = from;
      while(in[to] < in[cur] && out[cur] < out[to]) {
        int par = lca.parent[0][cur];
        int ne = next[cur];
        if(next[cur] == par && col[id[{min(par, cur), max(par, cur)}]] == 0) {
          // colorize
          col[id[{min(par, cur), max(par, cur)}]] = c;
          next[cur] = to;
        }
        cur = ne;
      }
    };
    setColor(u, w);
    setColor(v, w);
  }
  rep(i, n-1) cout << col[i] << endk;
  return 0;
}
