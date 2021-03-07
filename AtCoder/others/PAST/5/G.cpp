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
  vector<string> S(h); rep(i, h) cin >> S[i];
  int len = 0;
  rep(i, h) rep(j, w) if(S[i][j] == '#') len++;
  int dx[] = {0, -1, 0, 1};
  int dy[] = {-1, 0, 1, 0};
  vector<bool> vis(h*w);
  vector<pair<int, int>> path;
  auto dfs = [&](auto dfs, int x, int y) -> void {
    vis[x*w+y] = true;
    path.push_back({x, y});
    int cnt = 0;
    rep(k, 4) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      int ne = nx * w + ny;
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(vis[ne]) continue;
      if(S[nx][ny] == '.') continue;
      cnt++;
      dfs(dfs, nx, ny);
    }
    if(cnt == 0 && path.size() == len) {
      cout << len << endk;
      for(auto [x, y]: path) cout << x+1 << ' ' << y+1 << endk;
      exit(0);
    }
    vis[x*w+y] = false;
    path.pop_back();
  };
  rep(i, h) rep(j, w) if(S[i][j] == '#') dfs(dfs, i, j);
  return 0;
}
