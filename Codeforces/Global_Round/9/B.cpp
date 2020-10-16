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
  int n, m; cin >> n >> m;
  vector<vector<ll>> A(n, vector<ll>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  bool ok = true;
  rep(i, n) rep(j, m) {
    if(A[i][j] == 0) continue;
    int cnt = 0;
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      cnt++;
    }
    if(A[i][j] > cnt) ok = false;
  }
  if(!ok) {
    cout << "NO" << "\n";
    return;
  }
  rep(i, n) rep(j, m) {
    if(A[i][j] == 0) continue;
    int cnt = 0;
    vector<pair<int, int>> avail;
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(A[nx][ny]) cnt++;
      else avail.emplace_back(nx, ny);
    }
    if(A[i][j] > cnt) {
      int rem = A[i][j] - cnt;
      rep(i, rem) A[avail[i].first][avail[i].second]++;
    } else if(A[i][j] < cnt) {
      A[i][j] = cnt;
    }
  }
  rep(i, n) rep(j, m) {
    if(A[i][j] == 0) continue;
    int cnt = 0;
    vector<pair<int, int>> avail;
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(A[nx][ny]) cnt++;
      else avail.emplace_back(nx, ny);
    }
    if(A[i][j] > cnt) {
      int rem = A[i][j] - cnt;
      rep(i, rem) A[avail[i].first][avail[i].second]++;
    } else if(A[i][j] < cnt) {
      A[i][j] = cnt;
    }
  }
  cout << "YES" << "\n";
  rep(i, n) {
    rep(j, m) cout << A[i][j] << ' ';
    cout << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
