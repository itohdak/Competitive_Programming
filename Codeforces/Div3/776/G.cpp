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
const ll mod2 = 998244353;
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
  int s, t; cin >> s >> t;
  s--; t--;
  vector<vector<edge>> G(n*2+1);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back({v, 1});
    G[v].push_back({u, 1});
    G[n+u].push_back({n+v, 1});
    G[n+v].push_back({n+u, 1});
    G[u].push_back({n+v, 1});
    G[v].push_back({n+u, 1});
  }
  // G[t].push_back({n*2, 0});
  // G[n+t].push_back({n*2, 0});
  dijkstra(n*2+1, G, s);
  vector<int> id(n*2+1);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return dist[i] > dist[j];
  });
  cout << dist << endk;
  cout << id << endk;
  vector<ll> cnt(n*2+1);
  cnt[n*2] = 1;
  for(int i: id) {
    cout << i << endk;
    for(auto [ne, _]: G[i]) {
      cnt[ne] += cnt[i];
    }
  }
  cout << cnt << endk;
  cout << cnt[s] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
