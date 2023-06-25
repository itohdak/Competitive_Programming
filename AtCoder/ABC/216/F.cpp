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
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<pair<int, int>> P(n);
  rep(i, n) cin >> P[i].first;
  rep(i, n) cin >> P[i].second;
  sort(all(P));
  vector<vector<ll>> dp(n+1, vector<ll>(5001));
  rep(i, n) {
    (dp[i+1][P[i].second] += 1) %= mod;
    rep(j, 5001) {
      (dp[i+1][j] += dp[i][j]) %= mod;
      if(j+P[i].second <= 5000) (dp[i+1][j+P[i].second] += dp[i][j]) %= mod;
    }
  }
  rep(i, n+1) rep(j, 5000) (dp[i][j+1] += dp[i][j]) %= mod;
  int l = 0;
  ll ans = 0;
  while(l < n) {
    int r = l;
    while(r < n && P[r].first == P[l].first) r++;
    int mx = P[l].first;
    (ans += (dp[r][mx] - dp[l][mx] + mod)) %= mod;
    l = r;
  }
  cout << ans << endk;
  return 0;
}
