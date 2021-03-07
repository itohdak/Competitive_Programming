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
  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n+1, vector<int>(3, -inf));
  dp[0][0] = 0;
  rep(i, n) {
    chmax(dp[i][1], dp[i][0]);
    chmax(dp[i][2], dp[i][1]);
    chmax(dp[i+1][0], dp[i][0]);
    chmax(dp[i+1][1], dp[i][1]);
    chmax(dp[i+1][2], dp[i][2]);
    if(s[i] == 'a') {
      chmax(dp[i+1][0], dp[i][0]+1);
      chmax(dp[i+1][2], dp[i][2]+1);
    } else {
      chmax(dp[i+1][1], dp[i][1]+1);
    }
  }
  // cout << dp << endk;
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endk;
  return 0;
}
