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
  vector<vector<int>> A(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  vector<vector<int>> dp(h+2, vector<int>(1<<3, inf));
  dp[0][0] = 0;
  auto id = [](int i, int j, int k) -> int {
    return (i<<2)^(j<<1)^k;
  };
  auto judge = [&](int i, int i1, int i2, int i3) -> bool {
    if(i == 0) return true;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    map<int, int> mp = {{-1, i1}, {0, i2}, {1, i3}};
    int x = i-1;
    rep(y, w) {
      bool ok = false;
      rep(d, 4) {
        int nx = x+dx[d], ny = y+dy[d];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if((A[x][y]^i2) == (A[nx][ny]^mp[dx[d]])) ok = true;
      }
      if(!ok) return false;
    }
    return true;
  };
  rep(i, h+1) {
    rep(i1, 2) {
      rep(i2, 2) {
        rep(i3, 2) {
          if(dp[i][id(i1, i2, i3)] == inf) continue;
          rep(i4, 2) {
            if(judge(i, i2, i3, i4)) {
              chmin(dp[i+1][id(i2, i3, i4)], dp[i][id(i1, i2, i3)]+i4);
            }
          }
        }
      }
    }
  }
  int ans = inf;
  rep(j, 1<<3) chmin(ans, dp[h+1][j]);
  cout << (ans == inf ? -1 : ans) << endk;
  return 0;
}
