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
  int n, K; cin >> n >> K;
  string s, t; cin >> s >> t;
  if(t[0] == t[1]) {
    int cnt = 0;
    rep(i, n) if(s[i] == t[0]) cnt++;
    int mx = min(n, cnt+K);
    cout << mx * (mx-1) / 2 << endk;
    return;
  }
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(K+1, -inf)));
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, i+1) {
      rep(k, K+1) {
        // 何もしない
        if(s[i] == t[0] && j < n) chmax(dp[i+1][j+1][k], dp[i][j][k]);
        if(s[i] == t[1]) chmax(dp[i+1][j][k], dp[i][j][k]+j);
        if(s[i] != t[0] && s[i] != t[1]) chmax(dp[i+1][j][k], dp[i][j][k]);
        // t[0]に変える
        if(j < n && k < K) chmax(dp[i+1][j+1][k+1], dp[i][j][k]);
        // t[1]に変える
        if(k < K) chmax(dp[i+1][j][k+1], dp[i][j][k]+j);
      }
    }
  }
  ll ans = 0;
  rep(j, n+1) rep(k, K+1) {
    chmax(ans, dp[n][j][k]);
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
