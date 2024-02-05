#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

using mint = modint998244353;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<vector<mint>> dp(n+1, vector<mint>(m+2));
  REP(i, 1, m+1) dp[1][i] = 1;
  REP(i, 1, n) {
    rep(j, m+1) {
      if(k == 0) {
        dp[i+1][1] += dp[i][j];
        dp[i+1][m+1] -= dp[i][j];
      } else {
        dp[i+1][1] += dp[i][j];
        dp[i+1][max(1, j-k+1)] -= dp[i][j];
        dp[i+1][min(m+1, j+k)] += dp[i][j];
        dp[i+1][m+1] -= dp[i][j];
      }
    }
    rep(j, m+1) {
      dp[i+1][j+1] += dp[i+1][j];
    }
  }
  mint ans = 0;
  REP(j, 1, m+1) {
    ans += dp[n][j];
  }
  cout << ans.val() << endk;
  return 0;
}
