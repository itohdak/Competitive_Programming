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
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  auto id = [&](int x1, int y1, int x2, int y2) {
    int i = x1*n+y1, j = x2*n+y2;
    return i*n*n + j;
  };
  auto po = [&](int k) -> tuple<int, int, int, int> {
    int i = k/(n*n), j = k%(n*n);
    int x1 = i/n, y1 = i%n, x2 = j/n, y2 = j%n;
    return {x1, y1, x2, y2};
  };
  vector<pair<int, int>> pos;
  rep(i, n) {
    rep(j, n) {
      if(S[i][j] == 'P') pos.push_back({i, j});
    }
  }
  queue<pair<int, int>> Q;
  vector<bool> vis(n*n*n*n);
  vector<int> dist(n*n*n*n, inf);
  int s = id(pos[0].first, pos[0].second, pos[1].first, pos[1].second);
  dist[s] = 0;
  Q.push({s, 0});
  while(Q.size()) {
    auto [cur, d] = Q.front();
    Q.pop();
    if(vis[cur]) continue;
    if(dist[cur] < d) continue;
    vis[cur] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    auto [x1, y1, x2, y2] = po(cur);
    if(x1 == x2 && y1 == y2) continue;
    rep(k, 4) {
      int nx1 = x1+dx[k];
      int ny1 = y1+dy[k];
      int nx2 = x2+dx[k];
      int ny2 = y2+dy[k];
      if(nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n || S[nx1][ny1] == '#') {
        nx1 = x1, ny1 = y1;
      }
      if(nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n || S[nx2][ny2] == '#') {
        nx2 = x2, ny2 = y2;
      }
      int ne = id(nx1, ny1, nx2, ny2);
      if(!vis[ne] && dist[ne] > d+1) {
        dist[ne] = d+1;
        Q.push({ne, dist[ne]});
      }
    }
  }
  int ans = inf;
  rep(i, n) rep(j, n) {
    if(ans > dist[id(i, j, i, j)]) {
      chmin(ans, dist[id(i, j, i, j)]);
    }
  }
  cout << (ans == inf ? -1 : ans) << endk;
  return 0;
}
