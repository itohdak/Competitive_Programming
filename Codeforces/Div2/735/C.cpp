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
  ll n, m; cin >> n >> m;
  vector<vector<ll>> dp(32, vector<ll>(2, longinf));
  dp[31][0] = 0;
  for(int i=30; i>=0; i--) {
    if((m>>i)&1) {
      // choose 0
      chmin(dp[i][1], dp[i+1][1]+((((n>>i)&1)^0)<<i));
      // choose 1
      chmin(dp[i][1], dp[i+1][1]+((((n>>i)&1)^1)<<i));
      chmin(dp[i][0], dp[i+1][0]+((((n>>i)&1)^1)<<i));
    } else {
      // choose 0
      chmin(dp[i][1], dp[i+1][1]+((((n>>i)&1)^0)<<i));
      chmin(dp[i][0], dp[i+1][0]+((((n>>i)&1)^0)<<i));
      // choose 1
      chmin(dp[i][1], dp[i+1][1]+((((n>>i)&1)^1)<<i));
      chmin(dp[i][1], dp[i+1][0]+((((n>>i)&1)^1)<<i));
    }
  }
  cout << dp[0][1] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
