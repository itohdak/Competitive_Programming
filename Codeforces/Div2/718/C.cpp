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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<vector<int>> ans(n, vector<int>(n));
  int rem = 0;
  auto dfs = [&](auto dfs, int cur, int val) -> void {
    if(rem == 0) return;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int x = cur/n, y = cur%n;
    // rep(i, n) {
    //   rep(j, n) cout << ans[i][j] << ' ';
    //   cout << endk;
    // }
    // cout << rem << endk;
    // cout << "=====" << endl;
    // assert(ans[x][y] == 0);
    ans[x][y] = val;
    rem--;
    rep(k, 4) {
      int nx = x+dx[k], ny = y+dy[k];
      if(nx < 0 || nx >= n || ny < 0 || ny >= nx+1) continue;
      if(ans[nx][ny]) continue;
      dfs(dfs, nx*n+ny, val);
    }
  };
  rrep(i, n) {
    rem = P[i];
    dfs(dfs, i*n+i, P[i]);
  }
  bool ok = true;
  rep(i, n) rep(j, i+1) {
    if(ans[i][j] == 0) ok = false;
  }
  if(ok) {
    rep(i, n) {
      rep(j, i+1) {
        cout << ans[i][j] << ' ';
      }
      cout << endk;
    }
  } else {
    cout << -1 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
