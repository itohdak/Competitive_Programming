#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];
  vector<vector<bool>> vis(N, vector<bool>(N));
  auto bfs = [&](int sx, int sy) {
    int dx[] = {-1, 0};
    int dy[] = {0, -1};
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    while(!q.empty()) {
      auto tmp = q.front();
      int x = tmp.first;
      int y = tmp.second;
      q.pop();
      if(vis[x][y]) continue;
      vis[x][y] = true;
      if(S[x][y] == '0') continue;
      rep(i, 2) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(vis[nx][ny]) continue;
        q.emplace(nx, ny);
      }
    }
  };
  rep(i, N) bfs(N-1, i);
  rep(i, N) bfs(i, N-1);
  bool ok = true;
  rep(i, N) rep(j, N) if(S[i][j] == '1' && !vis[i][j]) ok = false;
  cout << (ok ? "YES" : "NO") << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
