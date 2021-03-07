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
  int a, b, k, t; cin >> a >> b >> k >> t;
  vector<vector<ll>> dp(t+1, vector<ll>(2*k*t+2));
  dp[0][k*t] = 1;
  rep(i, t) {
    rep(j, 2*k*t+1) {
      (dp[i+1][max(0, j-k)] += dp[i][j]) %= mod;
      (dp[i+1][min(2*k*t, j+k)+1] += mod - dp[i][j]) %= mod;
    }
    rep(j, 2*k*t+1) {
      if(j) (dp[i+1][j] += mod + dp[i+1][j-1]) %= mod;
    }
  }
  vector<ll> sum(2*k*t+2);
  rrep(i, 2*k*t+1) {
    (sum[i] = sum[i+1] + dp[t][i]) %= mod;
  }
  // cout << dp[t] << endk;
  // cout << sum << endk;
  ll ans = 0;
  rep(i, 2*k*t+1) {
    int need = b+i-a+1;
    if(need >= 2*k*t+2) continue;
    (ans += dp[t][i] * sum[max(0, need)] % mod) %= mod;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
