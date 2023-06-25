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
void solve() {
  int n, m; cin >> n >> m;
  vector<vector<edge>> G(4*n);
  rep(i, m) {
    int u, v; ll w;
    cin >> u >> v >> w;
    u--; v--;
    G[u+0*n].push_back({v+0*n, w});
    G[u+1*n].push_back({v+1*n, w});
    G[u+2*n].push_back({v+2*n, w});
    G[u+3*n].push_back({v+3*n, w});
    G[u+0*n].push_back({v+1*n, 2*w});
    G[u+2*n].push_back({v+3*n, 2*w});
    G[u+0*n].push_back({v+2*n, 0});
    G[u+1*n].push_back({v+3*n, 0});
    G[v+0*n].push_back({u+0*n, w});
    G[v+1*n].push_back({u+1*n, w});
    G[v+2*n].push_back({u+2*n, w});
    G[v+3*n].push_back({u+3*n, w});
    G[v+0*n].push_back({u+1*n, 2*w});
    G[v+2*n].push_back({u+3*n, 2*w});
    G[v+0*n].push_back({u+2*n, 0});
    G[v+1*n].push_back({u+3*n, 0});
  }
  dijkstra(4*n, G, 0);
  rep(i, n) if(i) cout << min(dist[i], dist[i+3*n]) << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
