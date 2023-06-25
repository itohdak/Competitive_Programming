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

using P = pair<ll, int>;

vector<ll> dist;
vector<int> par;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  par.assign(n, -1);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({dist[ne], ne});
        par[ne] = cur;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  set<int> vis;
  vector<vector<edge>> G2(n);
  vector<pair<int, int>> E;
  set<int> V;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    assert(!vis.count(cur));
    vis.insert(cur);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      if(vis.count(ne)) {
        E.push_back({cur, ne});
        V.insert(cur);
        V.insert(ne);
        continue;
      }
      G2[cur].push_back({ne, 1});
      G2[ne].push_back({cur, 1});
      dfs(dfs, ne, cur);
    }
  };
  dfs(dfs, 0, -1);
  LCA lca(n);
  lca.init(0, -1, 0, 0, G2);
  lca.build();
  auto len = [&](int i, int j) {
    int k = lca.query(i, j);
    return lca.len[i] + lca.len[j] - 2 * lca.len[k];
  };
  int q; cin >> q;
  rep(_, q) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    vector<int> A;
    for(auto i: V) A.push_back(i);
    A.push_back(u);
    A.push_back(v);
    sort(all(A));
    A.erase(unique(all(A)), end(A));
    auto id = [&](int i) -> int {
      return lower_bound(all(A), i) - begin(A);
    };
    int sz = A.size();
    vector<vector<edge>> G3(sz);
    rep(i, sz) {
      rep(j, sz) {
        if(j == i) continue;
        G3[i].push_back({j, len(A[i], A[j])});
      }
    }
    for(auto [u, v]: E) {
      G3[id(u)].push_back({id(v), 1});
      G3[id(v)].push_back({id(u), 1});
    }
    dijkstra(sz, G3, id(u));
    cout << dist[id(v)] << endk;
  }
  return 0;
}
