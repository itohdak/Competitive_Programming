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

int MAX = 303030;
vector<ll> pw(MAX);
vector<ll> dp(MAX);
void make() {
  pw[0] = 1;
  rep(i, MAX) if(i) pw[i] = pw[i-1]*2%mod;
  // vector<vector<vector<ll>>> dp2(MAX, vector<vector<ll>>(2, vector<ll>(2)));
  // dp2[0][0][0] = 1;
  // rep(i, MAX-1) {
  //   dp2[i+1][0][0] = (dp2[i][0][0] + dp2[i][1][0] + dp2[i][1][1]) % mod;
  //   dp2[i+1][1][0] = (dp2[i][0][0] + dp2[i][1][1]) % mod;
  //   dp2[i+1][1][1] = dp2[i][1][0];
  //   dp[i+1] = (2 * dp[i] + dp2[i][1][0]) % mod;
  // }
  dp[2] = 1;
  REP(i, 3, MAX) {
    dp[i] = (dp[i-1] + dp[i-2] * 2 + pw[i-2]) % mod;
  }
}
void solve() {
  ll n, m; cin >> n >> m;
  vector<string> S(n); rep(i, n) cin >> S[i];
  ll cnt = 0;
  rep(i, n) rep(j, m) if(S[i][j] == 'o') cnt++;
  ll ans = 0;
  // auto calc = [&](string s) {
  //   ll ret = 0;
  //   ll sz = s.size();
  //   int l = 0, r = 0;
  //   while(l < sz) {
  //     while(l < sz && s[l] == '*') l++;
  //     r = l;
  //     while(r < sz && s[r] == 'o') r++;
  //     int len = r - l;
  //     (ret += dp[len] * pw[cnt-len] % mod) %= mod;
  //     l = r;
  //   }
  //   return ret;
  // };
  // rep(i, n) {
  //   string s;
  //   rep(j, m) s += S[i][j];
  //   (ans += calc(s)) %= mod;
  // }
  // rep(j, m) {
  //   string s;
  //   rep(i, n) s += S[i][j];
  //   (ans += calc(s)) %= mod;
  // }
  rep(i, n) {
    ll l = 0, r = 0;
    while(l < m) {
      while(l < m && S[i][l] == '*') l++;
      r = l;
      while(r < m && S[i][r] == 'o') r++;
      ll len = r-l;
      (ans += pw[cnt-len] * dp[len] % mod) %= mod;
      l = r;
    }
  }
  rep(j, m) {
    ll l = 0, r = 0;
    while(l < n) {
      while(l < n && S[l][j] == '*') l++;
      r = l;
      while(r < n && S[r][j] == 'o') r++;
      ll len = r-l;
      (ans += pw[cnt-len] * dp[len] % mod) %= mod;
      l = r;
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int T = 1;
  while(T--) solve();
  return 0;
}
