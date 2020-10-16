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

void solve() {
  int n; cin >> n;
  vector<vector<edge>> G(n);
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back({v, 1});
    G[v].push_back({u, 1});
  }
  LCA lca(n);
  lca.init(0, -1, 0, 0, G);
  lca.build();
  int q; cin >> q;
  while(q--) {
    int x, y, a, b; ll k;
    cin >> x >> y >> a >> b >> k;
    x--; y--; a--; b--;
    vector<int> mn(2, inf); // even, odd
    vector<vector<int>> dist(4, vector<int>(4));
    vector<int> e = {a, b, x, y};
    rep(i, 4) REP(j, i+1, 4) {
      dist[i][j] = dist[j][i] = lca.len[e[i]] + lca.len[e[j]] - 2 * lca.len[lca.query(e[i], e[j])];
    }
    int dab = dist[0][1];
    int daxyb = dist[0][2] + 1 + dist[3][1];
    int dayxb = dist[0][3] + 1 + dist[2][1];
    chmin(mn[dab%2], dab);
    chmin(mn[daxyb%2], daxyb);
    chmin(mn[dayxb%2], dayxb);
    cout << (k >= mn[k%2] ? "YES" : "NO") << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
