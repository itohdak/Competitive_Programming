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
  int n, m; cin >> n >> m;
  vector<ll> A(n), B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
  dp[0][0] = 0;
  rep(i, n) rep(j, m) {
    chmin(dp[i+1][j], dp[i][j]+1);
    chmin(dp[i][j+1], dp[i][j]+1);
    chmin(dp[i+1][j+1], dp[i][j]+1);
    if(A[i] == B[j]) chmin(dp[i+1][j+1], dp[i][j]);
  }
  // cout << dp << endk;
  // cout << dp[n][m] << endk;
  int ans = inf;
  rep(i, n+1) chmin(ans, dp[i][m]+n-i);
  rep(i, m+1) chmin(ans, dp[n][i]+m-i);
  cout << ans << endk;
  return 0;
}
