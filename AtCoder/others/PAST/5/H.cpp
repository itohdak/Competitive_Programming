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
  int r, c; cin >> r >> c;
  r--; c--;
  auto id = [&](int x, int y) {
    return x * w + y;
  };
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<bool> vis(h*w);
  vector<int> dist(h*w, inf);
  auto bfs = [&]() {
    queue<pair<int, int>> q;
    dist[id(r, c)] = 0;
    q.push({id(r, c), 0});
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    char dd[] = {'>', 'v', '<', '^'};
    while(q.size()) {
      auto [cur, d] = q.front(); q.pop();
      int x = cur / w;
      int y = cur % w;
      if(dist[cur] != d) continue;
      if(vis[cur]) continue;
      vis[cur] = true;
      rep(k, 4) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        int ne = id(nx, ny);
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(S[nx][ny] == '#' || !(S[nx][ny] == dd[k] || S[nx][ny] == '.')) continue;
        if(dist[ne] > dist[cur] + 1) {
          dist[ne] = dist[cur] + 1;
          q.push({ne, dist[ne]});
        }
      }
    }
  };
  bfs();
  rep(i, h) {
    rep(j, w) {
      if(S[i][j] == '#') cout << '#';
      else if(vis[id(i, j)]) cout << 'o';
      else cout << 'x';
    }
    cout << endk;
  }
  return 0;
}
