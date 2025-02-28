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
  int n, k; cin >> n >> k;
  vector<vector<ll>> dp(n+2, vector<ll>(2));
  dp[0][1] = 1;
  ll ans = 0;
  rep(i, k) {
    if(i%2==0) { // ->
      rep(j, n+2) dp[j][0] = 0;
      if(i == 0) dp[1][0] = 1;
      for(int j=2; j<n+2; j++) (dp[j][0] = dp[j-1][0] + dp[j-1][1]) %= mod;
      (ans += dp[n+1][0]) %= mod;
      // rep(j, n+2) cout << dp[j][0] << ' '; cout << endk;
    } else { // <-
      rep(j, n+2) dp[j][1] = 0;
      for(int j=n-1; j>=0; j--) (dp[j][1] = dp[j+1][1] + dp[j+1][0]) %= mod;
      (ans += dp[0][1]) %= mod;
      // rep(j, n+2) cout << dp[j][1] << ' '; cout << endk;
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
