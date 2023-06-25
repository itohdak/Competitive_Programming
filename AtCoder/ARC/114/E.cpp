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
#define MAX_N 200005
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
  int h, w; cin >> h >> w;
  int h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
  h1--; w1--; h2--; w2--;
  int mnh = min(h1, h2), mxh = max(h1, h2);
  int mnw = min(w1, w2), mxw = max(w1, w2);
  ll ans = 0;
  int ng = (mxh-mnh)+(mxw-mnw);
  int rem = h+w-2-ng;
  ll tmp = 1;
  for(int i=0; i<=rem; i++) {
    (ans += (i+1) * modinv(h+w-2-i) % mod * tmp % mod) %= mod;
    (tmp += mod - ng * modinv(h+w-2-i) % mod) %= mod;
  }
  (ans *= ng) %= mod;
  cout << ans << endk;
  return 0;
}
