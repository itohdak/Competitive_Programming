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
  ll p; cin >> p;
  int m = 3*n-2;
  vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(m+1)));
  dp[1][0][0] = 1;
  dp[3][0][1] = 1;
  rep(i, n-1) {
    REP(j, 2*i, 3*i+2) {
    // rep(j, m+1) {
      rep(k, 4) {
        if((k>>0)&1) {
          if((k>>1)&1) {
            if(j+1 < m+1) (dp[1][i+1][j+1] += dp[k][i][j]) %= p; // 1
            if(j+1 < m+1) (dp[2][i+1][j+1] += dp[k][i][j]) %= p; //    2
            if(j+2 < m+1) (dp[3][i+1][j+2] += dp[k][i][j]) %= p; // 1, 2
            if(j+2 < m+1) (dp[3][i+1][j+2] += dp[k][i][j]) %= p; // 1,    3
            if(j+2 < m+1) (dp[3][i+1][j+2] += dp[k][i][j]) %= p; //    2, 3
            if(j+3 < m+1) (dp[3][i+1][j+3] += dp[k][i][j]) %= p; // 1, 2, 3
          } else {
            if(j+2 < m+1) (dp[1][i+1][j+2] += dp[k][i][j]) %= p; // 1, 2
            if(j+3 < m+1) (dp[3][i+1][j+3] += dp[k][i][j]) %= p; // 1, 2, 3
          }
        } else {
          if((k>>1)&1) {
            if(j+2 < m+1) (dp[2][i+1][j+2] += dp[k][i][j]) %= p; // 1, 2
            if(j+3 < m+1) (dp[3][i+1][j+3] += dp[k][i][j]) %= p; // 1, 2, 3
          }
        }
      }
    }
  }
  // rep(i, n) cout << dp[i] << endk;
  for(int i=m-1; i>=2*n-1; i--) {
    cout << dp[3][n-1][i] << ' ';
  }
  cout << endk;
  return 0;
}
