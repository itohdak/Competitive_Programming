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
// const ll mod = 1e9+7;
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  vector<vector<ll>> memo(n, vector<ll>(n+1, 0));
  rep(i, n) memo[i][i+1] = 1;
  vector<vector<ll>> dp(n, vector<ll>(n+1));
  rep(l, n) dp[l][l+1] = 1;
  for(int len=1; len<=n; len++) {
    rep(l, n) {
      if(l+len > n) break;
      // for(int i=l+1; i<l+len; i++) {
      //   int j = l+len-1;
      //   if(i < j || i == l+1 || P[j] > P[i-1]) {
      //     dp[l][j+1] += dp[l][i] * memo[i][j+1] % mod;
      //     dp[l][j+1] %= mod;
      //   }
      // }
      dp[l] = vector<ll>(n+1);
      dp[l][l+1] = 1;
      for(int i=l+1; i<l+len; i++) {
        for(int j=i; j<l+len; j++) {
          if(j+1 == l+len || P[j+1] > P[i]) {
            dp[l][j+1] += dp[l][i] * memo[i][j+1] % mod;
            dp[l][j+1] %= mod;
          }
        }
      }
      memo[l][l+len] = dp[l][l+len];
    }
  }
  cout << memo << endk;
  cout << memo[0][n] << endk;
  return 0;
}
