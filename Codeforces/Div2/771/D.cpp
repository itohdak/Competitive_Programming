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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  queue<tuple<int, int, int>> q;
  rep(i, n-1) rep(j, m-1) {
    bool ok = true;
    rep(dx, 2) rep(dy, 2) {
      if(A[i+dx][j+dy] != A[i][j]) ok = false;
    }
    if(!ok) continue;
    q.push({i, j, A[i][j]});
  }
  vector<vector<bool>> done(n, vector<bool>(m));
  vector<tuple<int, int, int>> ans;
  while(q.size()) {
    auto [x, y, c] = q.front(); q.pop();
    ans.push_back({x, y, c});
    rep(dx, 2) rep(dy, 2) {
      A[x+dx][y+dy] = 0;
    }
    // cout << x << ' ' << y << ' ' << c << endk;
    // rep(i, n) cout << A[i] << endk;
    // cout << "===" << endk;
    for(int i=x-1; i<=x+1; i++) {
      for(int j=y-1; j<=y+1; j++) {
        if(i < 0 || j < 0) continue;
        if(i+1 >= n || j+1 >= m) continue;
        if(i == x && j == y) continue;
        bool ok = true;
        int col = 0;
        rep(dx, 2) rep(dy, 2) {
          if(A[i+dx][j+dy] == 0) continue;
          if(col == 0) col = A[i+dx][j+dy];
          if(A[i+dx][j+dy] != col) ok = false;
        }
        if(!ok) continue;
        if(col == 0) continue;
        if(!done[i][j]) {
          q.push({i, j, col});
          done[i][j] = true;
        }
      }
    }
  }
  rep(i, n) rep(j, m) {
    if(A[i][j]) {
      cout << -1 << endk;
      return;
    }
  }
  cout << ans.size() << endk;
  reverse(all(ans));
  for(auto [x, y, c]: ans) cout << x+1 << ' ' << y+1 << ' ' << c << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
