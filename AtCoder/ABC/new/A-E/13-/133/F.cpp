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
  int col;
  edge(int to, ll cost, int col) : to(to), cost(cost), col(col) {}
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
  rep(i, n-1) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--;
    G[a].push_back({b, d, c});
    G[b].push_back({a, d, c});
  }
  vector<int> in(n), out(n);
  int cnt = 0;
  map<int, vector<pair<int, int>>> mp;
  map<int, vector<pair<int, int>>> mp2;
  auto dfs = [&](auto dfs, int cur, int par, int col, int dist) -> void {
    in[cur] = cnt++;
    if(par != -1) {
      mp[col].push_back({in[cur], dist});
      mp2[col].push_back({in[cur], 1});
    }
    for(auto [ne, d, c]: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur, c, d);
    }
    out[cur] = cnt++;
    if(par != -1) {
      mp[col].push_back({out[cur], -dist});
      mp2[col].push_back({out[cur], -1});
    }
  };
  dfs(dfs, 0, -1, -1, 0);
  for(auto& [c, v]: mp) {
    int sum = 0;
    for(auto& [_, s]: v) {
      s += sum;
      sum = s;
    }
  }
  for(auto& [c, v]: mp2) {
    int sum = 0;
    for(auto& [_, s]: v) {
      s += sum;
      sum = s;
    }
  }
  LCA lca(n);
  lca.init(0, -1, 0, 0, G);
  lca.build();
  auto get_len = [&](int v, int x, int y) -> int {
    int ret = lca.len[v];
    if(mp.count(x)) {
      auto itr = upper_bound(all(mp[x]), make_pair(in[v], inf));
      auto itr2 = upper_bound(all(mp2[x]), make_pair(in[v], inf));
      if(itr != mp[x].begin()) {
        itr--; itr2--;
        ret -= (*itr).second;
        ret += (*itr2).second * y;
      }
    }
    return ret;
  };
  rep(i, q) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    u--; v--;
    int w = lca.query(u, v);
    ll len = get_len(u, x, y) + get_len(v, x, y) - 2 * get_len(w, x, y);
    cout << len << endk;
  }
  return 0;
}
