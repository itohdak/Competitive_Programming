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
  vector<int> P(n);
  rep(i, n) cin >> P[i];
  vector<vector<ld>> dp(n+1, vector<ld>(n+1, -longinf));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, n+1) {
      if(dp[i][j] == -longinf) continue;
      chmax(dp[i+1][j], dp[i][j]);
      if(j+1 < n+1) chmax(dp[i+1][j+1], dp[i][j]*9/10+P[i]);
    }
  }
  ld ans = -longinf;
  ld b = 1;
  REP(j, 1, n+1) {
    chmax(ans, dp[n][j]/b-(ld)1200/sqrtl(j));
    ((b *= 9) /= 10) += 1;
  }
  cout << fixed << setprecision(10) << ans << endk;
  return 0;
}
