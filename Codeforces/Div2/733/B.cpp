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
  int h, w; cin >> h >> w;
  vector<vector<bool>> ans(h, vector<bool>(w));
  auto ok = [&](int i, int j) {
    for(int dx=-1; dx<=1; dx++) {
      for(int dy=-1; dy<=1; dy++) {
        int nx = i+dx, ny = j+dy;
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(ans[nx][ny]) return false;
      }
    }
    return true;
  };
  rep(i, h) {
    if(ok(i, 0)) {
      ans[i][0] = true;
    }
  }
  rep(j, w) {
    if(ok(h-1, j)) {
      ans[h-1][j] = true;
    }
  }
  rrep(i, h) {
    if(ok(i, w-1)) {
      ans[i][w-1] = true;
    }
  }
  rrep(j, w) {
    if(ok(0, j)) {
      ans[0][j] = true;
    }
  }
  rep(i, h) {
    rep(j, w) cout << ans[i][j];
    cout << endk;
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
