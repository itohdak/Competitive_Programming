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
  int n; cin >> n;
  vector<vector<int>> dp(n+2, vector<int>(n+1));
  dp[1][0] = 1;
  auto dfs = [&](auto dfs, int i) -> void {
    if(i == n+2) {
      cout << n << endk;
      rep(j, n+1) cout << dp[n+1][j] << ' '; cout << endk;
      cout << n-1 << endk;
      rep(j, n) cout << dp[n][j] << ' '; cout << endk;
      exit(0);
    }
    // +1
    {
      rep(j, n+1) if(j) dp[i][j] = dp[i-1][j-1];
      bool ok = true;
      rep(j, n+1) {
        dp[i][j] += dp[i-2][j];
        if(abs(dp[i][j])>1) {
          ok = false;
          break;
        }
      }
      if(ok) dfs(dfs, i+1);
    }
    // -1
    {
      rep(j, n+1) {
        if(j) dp[i][j] = dp[i-1][j-1];
        else  dp[i][j] = 0;
      }
      // cout << i << ": " << dp[i] << endk;
      // cout << i-1 << ": " << dp[i-1] << endk;
      // cout << i-2 << ": " << dp[i-2] << endk;
      bool ok = true;
      rep(j, n+1) {
        dp[i][j] -= dp[i-2][j];
        if(abs(dp[i][j])>1) {
          ok = false;
          break;
        }
      }
      if(ok) dfs(dfs, i+1);
    }
  };
  dfs(dfs, 2);
  cout << -1 << endk;
  return 0;
}
