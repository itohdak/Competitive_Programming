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
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
  vector<vector<pair<int, int>>> par(n+1, vector<pair<int, int>>(m+1));
  dp[0][0] = 0;
  rep(i, n+1) rep(j, m+1) {
    if(i < n && j < m && s[i] == t[j]) {
      if(dp[i+1][j+1] < dp[i][j]+1) {
        dp[i+1][j+1] = dp[i][j]+1;
        par[i+1][j+1] = {i, j};
      }
    }
    if(i+1 <= n && dp[i+1][j] < dp[i][j]) {
      dp[i+1][j] = dp[i][j];
      par[i+1][j] = {i, j};
    }
    if(j+1 <= m && dp[i][j+1] < dp[i][j]) {
      dp[i][j+1] = dp[i][j];
      par[i][j+1] = {i, j};
    }
  }
  // cout << dp[n][m] << endk;
  // cout << dp << endk;
  int i = n, j = m;
  string ans;
  while(i || j) {
    auto [ni, nj] = par[i][j];
    if(dp[i][j] != dp[ni][nj]) {
      ans += s[ni];
    }
    i = ni, j = nj;
  }
  reverse(all(ans));
  cout << ans << endk;
  return 0;
}
