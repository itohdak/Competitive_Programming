#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  int good = 0, bad = 0;
  rep(i, n) rep(j, m) {
    if(S[i][j] == 'G') good++;
    else if(S[i][j] == 'B') bad++;
  }
  if(good == 0) {
    cout << "Yes" << endl;
    return;
  }

  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  bool ok = true;
  rep(i, n) rep(j, m) {
    if(S[i][j] == 'B') {
      rep(k, 4) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(S[nx][ny] == 'G') ok = false;
        else if(S[nx][ny] == '.') S[nx][ny] = '#';
      }
    }
  }
  if(!ok) {
    cout << "No" << endl;
    return;
  }

  vector<vector<bool>> vis(n, vector<bool>(m));
  int cnt = 0;
  function<void(int, int)> dfs = [&](int x, int y) {
    // cout << x << ' ' << y << endl;
    if(S[x][y] == '#') return;
    if(S[x][y] == 'G') cnt++;
    vis[x][y] = true;
    rep(k, 4) {
      int nx = x+dx[k];
      int ny = y+dy[k];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(vis[nx][ny]) continue;
      dfs(nx, ny);
    }
  };
  dfs(n-1, m-1);
  // cout << cnt << ' ' << good << endl;
  cout << (cnt == good ? "Yes" : "No") << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
