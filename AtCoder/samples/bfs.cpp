#include "header.hpp"

template<typename T>
vector<T> bfs(int s, int n, vector<vector<pair<int, T>>>& G) {
  vector<T> dist(n, longinf);
  queue<pair<int, T>> q;
  q.push({s, 0});
  dist[s] = 0;
  vector<bool> vis(n);
  while(!q.empty()) {
    auto [cur, d] = q.front(); q.pop();
    if(vis[cur]) continue;
    if(dist[cur] < d) continue;
    vis[cur] = true;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({ne, dist[ne]});
      }
    }
  }
  return dist;
}

void bfs_lambda() {
  auto bfs = [&](int s, int n, vector<vector<pair<int, ll>>>& G) {
    vector<ll> dist(n, longinf);
    queue<pair<int, ll>> q;
    q.push({s, 0});
    dist[s] = 0;
    vector<bool> vis(n);
    while(!q.empty()) {
      auto [cur, d] = q.front(); q.pop();
      if(vis[cur]) continue;
      if(dist[cur] < d) continue;
      vis[cur] = true;
      for(auto [ne, cost]: G[cur]) {
        if(dist[ne] > dist[cur] + cost) {
          dist[ne] = dist[cur] + cost;
          q.push({ne, dist[ne]});
        }
      }
    }
    return dist;
  };
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, s, t; cin >> n >> m >> s >> t;
  vector<vector<pair<int, ll>>> G(n);
  rep(i, m) {
    int a, b; ll c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    // G[b].push_back({a, c});
  }
  auto D = bfs(s, n, G);
  cout << D[t] << endk;
  return 0;
}
