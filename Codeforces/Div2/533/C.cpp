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

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
#define MAX_N 2000005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r);
  ans = (ans * finv[r]) % mod;
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n; ll l, r; cin >> n >> l >> r;
  l--;
  vector<ll> cnt(3);
  cnt[0] = r/3-l/3;
  cnt[1] = (r+2)/3-(l+2)/3;
  cnt[2] = (r+1)/3-(l+1)/3;
  // cout << cnt << endk;
  vector<vector<ll>> dp(n+1, vector<ll>(3));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 3) {
      (dp[i+1][j] += dp[i][j] * cnt[0] % mod) %= mod;
      (dp[i+1][(j+2)%3] += dp[i][j] * cnt[2] % mod) %= mod;
    }
  }
  // cout << dp << endk;
  ll ans = 0;
  for(int i=0; i<=n; i++) {
    (ans += comb(n, i) * modpow(cnt[1], i) % mod * dp[n-i][(3-i%3)%3] % mod) %= mod;
  }
  cout << ans << endk;
  return 0;
}
