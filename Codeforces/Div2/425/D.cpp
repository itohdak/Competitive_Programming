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
  rep(i, n-1) {
    int p; cin >> p;
    p--;
    G[p].push_back({i+1, 1});
    G[i+1].push_back({p, 1});
  }

  LCA lca(n);
  lca.init(0, -1, 0, 0, G);
  lca.build();

  vector<int> dist(n), in(n), out(n);
  int id = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(par != -1) dist[cur] = dist[par] + 1;
    else dist[cur] = 0;
    in[cur] = id++;
    for(auto [ne, _]: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
      }
    }
    out[cur] = id++;
  };
  dfs(dfs, 0, -1);

  auto isUnder = [&](int i, int j) {
    return in[i] <= in[j] && out[j] <= out[i];
  };
  while(q--) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--; c--;
    vector<int> pos = {a, b, c};
    sort(all(pos));
    int mx = 0;
    do {
      int s = pos[0], f = pos[1], t = pos[2];
      int s2f = lca.query(s, f);
      int t2f = lca.query(t, f);
      int s2t = lca.query(s, t);
      int lower = (isUnder(s2f, t2f) ? t2f : s2f);
      // cout << s << ' ' << f << ' ' << t << ' ' << lower << ' ' << s2t << endk;
      chmax(mx, dist[f]-dist[lower]+max(0, dist[s2t]-dist[lower])+1);
    } while(next_permutation(all(pos)));
    cout << mx << endk;
  }
  return 0;
}
