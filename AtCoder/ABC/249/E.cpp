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

ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, p; cin >> n >> p;
  vector<vector<ll>> dp(n+1, vector<ll>(n));
  vector<vector<ll>> sum(n+2, vector<ll>(n));
  dp[0][0] = modinv(25, p) * 26 % p; // 26/25
  sum[1][0] = dp[0][0];
  REP(i, 1, n+1) {
    rep(j, n) {
      int l = 1, r = 10;
      int lg = 1;
      while(i-l+1 >= 0) {
        if(j-lg-1 >= 0) {
          (dp[i][j] += (sum[max(0, i-l+1)][j-lg-1] - sum[max(0, i-r+1)][j-lg-1] + p) * 25) %= p;
        }
        l *= 10;
        r *= 10;
        lg++;
      }
      sum[i+1][j] = (sum[i][j] + dp[i][j]) % p;
    }
  }
  ll ans = 0;
  rep(i, n) (ans += dp[n][i]) %= p;
  cout << ans << endk;
  return 0;
}
