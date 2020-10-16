#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
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
  int ans = inf;
  string t[] = {"LL", "LR", "RL", "RR"};
  rep(k, 4) {
    vector<vector<int>> dp(n-1, vector<int>(4, n+5));
    dp[0][k] = (s[0]!=t[k][0])+(s[1]!=t[k][1]);
    rep(i, n-2) {
      dp[i+1][0] = dp[i][2] + (s[i+2]!='L');
      dp[i+1][1] = min(dp[i][0], dp[i][2]) + (s[i+2]!='R');
      dp[i+1][2] = min(dp[i][1], dp[i][3]) + (s[i+2]!='L');
      dp[i+1][3] = dp[i][1] + (s[i+2]!='R');
    }
    // cout << dp << endk;
    switch(k) {
    case 0:
      chmin(ans, min({dp[n-2][1], dp[n-2][3]}));
      break;
    case 1:
      chmin(ans, min({dp[n-2][1], dp[n-2][2], dp[n-2][3]}));
      break;
    case 2:
      chmin(ans, min({dp[n-2][0], dp[n-2][1], dp[n-2][2]}));
      break;
    default:
      chmin(ans, min({dp[n-2][0], dp[n-2][2]}));
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
