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
  int cost;
  edge(int t, int c): to(t), cost(c) {};
};

using P = pair<int, int>;

vector<int> dist;
// vector<int> par;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, inf);
  // par.assign(n, -1);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({dist[ne], ne});
        // par[ne] = cur;
      }
    }
  }
}
void solve() {
  int n, m; cin >> n >> m;
  vector<vector<edge>> G(n+n*51);
  rep(i, m) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    G[u].push_back({n+v*51+w, 0});
    G[v].push_back({n+u*51+w, 0});
    rep(j, 51) {
      G[n+u*51+j].push_back({v, (j+w)*(j+w)});
      G[n+v*51+j].push_back({u, (j+w)*(j+w)});
    }
  }
  dijkstra(n+n*51, G, 0);
  rep(i, n) cout << (dist[i] == inf ? -1 : dist[i]) << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
