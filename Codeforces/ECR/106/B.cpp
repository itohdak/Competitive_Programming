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
  string s; cin >> s;
  int n = s.size();
  vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(2, vector<bool>(2)));
  dp[0][0][0] = true;
  rep(i, n) {
    if(s[i] == '0') {
      if(dp[i][0][0] || dp[i][0][1]) dp[i+1][0][0] = true;
      if(dp[i][0][0]) dp[i+1][0][1] = true;
      // if(dp[i][0][0] || dp[i][0][1]) dp[i+1][1][0] = true;
      if(dp[i][1][0]) dp[i+1][1][1] = true;
    } else {
      // if(dp[i][0][0] || dp[i][0][1]) dp[i+1][0][0] = true;
      if(dp[i][0][0]) dp[i+1][0][1] = true;
      if(dp[i][0][0] || dp[i][0][1] || dp[i][1][0] || dp[i][1][1]) dp[i+1][1][0] = true;
      if(dp[i][1][0]) dp[i+1][1][1] = true;
    }
  }
  if(dp[n][0][0] || dp[n][0][1] || dp[n][1][0] || dp[n][1][1]) cout << "YES" << endk;
  else cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
