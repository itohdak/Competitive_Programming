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
  int n; cin >> n;
  string s; cin >> s;
  vector<vector<ll>> dp(n+1, vector<ll>(4));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 4) (dp[i+1][j] += dp[i][j]*(s[i]=='?' ? 3 : 1)) %= mod;
    switch(s[i]) {
    case 'a':
      (dp[i+1][1] += dp[i][0]) %= mod;
      break;
    case 'b':
      (dp[i+1][2] += dp[i][1]) %= mod;
      break;
    case 'c':
      (dp[i+1][3] += dp[i][2]) %= mod;
      break;
    default:
      (dp[i+1][1] += dp[i][0]) %= mod;
      (dp[i+1][2] += dp[i][1]) %= mod;
      (dp[i+1][3] += dp[i][2]) %= mod;
    }
  }
  cout << dp[n][3] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
