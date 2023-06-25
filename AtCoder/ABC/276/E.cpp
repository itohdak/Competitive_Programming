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

  int n = h*w;
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};

  vector<vector<pair<int, ll>>> G(n);
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '#') continue;
      G[i*w+j].push_back({nx*w+ny, 1});
    }
  }
  int sx, sy;
  rep(i, h) rep(j, w) {
    if(S[i][j] == 'S') {
      sx = i, sy = j;
    }
  }

  vector<ll> dist(n, longinf);
  vector<int> col(n, -1);
  queue<tuple<int, ll, int>> q;
  int s = sx*w+sy;
  dist[s] = 0;
  rep(k, 4) {
    int nx = sx+dx[k];
    int ny = sy+dy[k];
    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
    if(S[nx][ny] == '#') continue;
    int ne = nx*w+ny;
    q.push({ne, 1, k});
    dist[ne] = 1;
    col[ne] = k;
  }
  vector<bool> vis(n);
  while(!q.empty()) {
    auto [cur, d, c] = q.front(); q.pop();
    if(vis[cur]) {
      if(col[cur] != -1 && col[cur] != c) {
        cout << "Yes" << endk;
        return 0;
      }
      continue;
    }
    if(dist[cur] < d) continue;
    vis[cur] = true;
    col[cur] = c;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] >= dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({ne, dist[ne], c});
      }
    }
  }
  cout << "No" << endk;
  return 0;
}
