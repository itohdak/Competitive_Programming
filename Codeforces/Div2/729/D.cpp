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
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<pair<char, int>> op(n);
  for(auto& [c, x]: op) {
    cin >> c;
    if(c == '+') cin >> x;
  }
  ll ans = 0;
  rep(i, n) {
    if(op[i].first == '-') continue;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    dp[0][0] = 1;
    rep(j, n) {
      rep(k, n+1) {
        (dp[j+1][k] += dp[j][k]) %= mod;
        if(j < i) {
          if(op[j].first == '-') {
            if(k == 0) (dp[j+1][k] += dp[j][k]) %= mod;
            else (dp[j+1][k-1] += dp[j][k]) %= mod;
          } else {
            if(op[j].second <= op[i].second) {
              if(k+1 <= n) (dp[j+1][k+1] += dp[j][k]) %= mod;
            } else {
              (dp[j+1][k] += dp[j][k]) %= mod;
            }
          }
        } else if(j == i) {
          // (dp[j+1][k] += dp[j][k]) %= mod;
        } else {
          if(op[j].first == '-') {
            if(k == 0) continue;
            else (dp[j+1][k-1] += dp[j][k]) %= mod;
          } else {
            if(op[j].second < op[i].second) {
              if(k+1 <= n) (dp[j+1][k+1] += dp[j][k]) %= mod;
            } else {
              (dp[j+1][k] += dp[j][k]) %= mod;
            }
          }
        }
      }
    }
    // cout << i << ' ' << dp << endk;
    ll sum = 0;
    rep(i, n+1) (sum += dp[n][i]) %= mod;
    (ans += op[i].second * sum % mod) %= mod;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
