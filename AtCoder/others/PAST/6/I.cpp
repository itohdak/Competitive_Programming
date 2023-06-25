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
  vector<vector<ll>> A(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(h+w, -longinf)));
  dp[0][0][1] = A[0][0];
  dp[0][0][0] = 0;
  rep(i, h) rep(j, w) {
    int dx[] = {1, 0};
    int dy[] = {0, 1};
    rep(k, 2) {
      int nx = i + dx[k];
      int ny = j + dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      rep(l, h+w-1) {
        chmax(dp[nx][ny][l+1], dp[i][j][l] + A[nx][ny]);
        chmax(dp[nx][ny][l], dp[i][j][l]);
      }
    }
  }
  vector<ll> ans(h+w);
  rep(i, h) rep(j, w) rep(k, h+w) chmax(ans[k], dp[i][j][k]);
  REP(i, 1, h+w) cout << ans[i] << endk;
  return 0;
}
