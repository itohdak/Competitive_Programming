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
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> S(k+1);
  S[0] = n;
  vector<vector<ll>> pw(k+1, vector<ll>(n, 1));
  copy(all(A), pw[1].begin());
  for(int i=1; i<=k; i++) {
    rep(j, n) {
      (S[i] += pw[i][j] * finv[i] % mod) %= mod;
      if(i+1 < k+1) pw[i+1][j] = pw[i][j] * A[j] % mod;
    }
  }
  ll modinv2 = modinv(2);
  for(int i=1; i<=k; i++) {
    ll ans = 0;
    rep(j, i+1) (ans += S[j] * S[i-j] % mod) %= mod;
    (ans *= fac[i]) %= mod;
    ll sub = 0;
    ll pw2 = modpow(2, i);
    rep(j, n) (sub += pw2 * pw[i][j] % mod) %= mod;
    (ans += mod - sub) %= mod;
    (ans *= modinv2) %= mod;
    cout << ans << endk;
  }
  return 0;
}
