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
  vector<vector<int>> B(h, vector<int>(w));
  vector<vector<int>> D(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, h) rep(j, w) cin >> B[i][j];
  rep(i, h) rep(j, w) D[i][j] = abs(A[i][j]-B[i][j]);
  int bias = 80*160;
  vector<vector<bool>> dp(h*w, vector<bool>(bias*2+1));
  dp[0][bias+D[0][0]] = 1;
  dp[0][bias-D[0][0]] = 1;
  rep(i, h+w-1) {
    rep(j, i+1) {
      int x = j, y = i-j;
      if(x < 0 || y < 0 || x >= h || y >= w) continue;
      int cur = x*w+y;
      rep(k, bias*2+1) {
        if(!dp[cur][k]) continue;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        rep(l, 4) {
          int nx = x+dx[l];
          int ny = y+dy[l];
          if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
          int ne = nx*w+ny;
          if(k+D[nx][ny] < bias*2+1) {
            dp[ne][k+D[nx][ny]] = true;
          }
          if(k-D[nx][ny] >= 0) {
            dp[ne][k-D[nx][ny]] = true;
          }
        }
      }
    }
  }
  int ans = inf;
  rep(i, bias*2+1) {
    if(!dp[h*w-1][i]) continue;
    int cur = i-bias;
    chmin(ans, abs(cur));
  }
  cout << ans << endk;
  return 0;
}
