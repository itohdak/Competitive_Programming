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
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> d;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}

vector<vector<int>> G2;
vector<int> Tpl;
vector<bool> vis;

/* topological sort */
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G2[cur]) dfs(ne);
  Tpl.push_back(cur);
}

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<edge>> G(n);
  vector<pair<int, int>> E(m);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    E[i] = {u, v};
    G[u].push_back({v, 1});
  }
  dijkstra(0, n, G);
  G2 = vector<vector<int>>(2*n);
  Tpl = vector<int>();
  vis = vector<bool>(2*n);
  rep(i, m) {
    auto [u, v] = E[i];
    if(d[u] < d[v]) {
      G2[v].push_back(u);
      G2[n+v].push_back(n+u);
    } else {
      G2[n+v].push_back(u);
    }
  }
  rep(i, 2*n) dfs(i);
  reverse(all(Tpl));
  vector<int> ans(2*n);
  rep(i, 2*n) ans[i] = d[i%n];
  for(int cur: Tpl) {
    for(int ne: G2[cur]) {
      chmin(ans[ne], ans[cur]);
    }
  }
  rep(i, n) cout << ans[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
