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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h);
  rep(i, h) cin >> S[i];
  vector<vector<pair<int, ll>>> G(h*w);
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    int dx[] = {1, 0};
    int dy[] = {0, 1};
    rep(k, 2) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx >= h || ny >= w) continue;
      if(S[nx][ny] == '#') continue;
      G[i*w+j].push_back({nx*w+ny, 1});
    }
  }
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
  auto dist = bfs(0, h*w, G);
  ll ans = 0;
  rep(i, h*w) {
    if(dist[i] == longinf) continue;
    chmax(ans, dist[i]);
  }
  cout << ans+1 << endk;
  return 0;
}
