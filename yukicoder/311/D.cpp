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

void prime_factorization(ll N, map<ll, int>& res) {
  if(N == 1 || N == 0) return;
  ll n = N;
  ll i = 2;
  while(n >= i * i) {
    while(n % i == 0) {
      if(res.count(i)) res[i]++;
      else res[i] = 1;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
  }
  if(n != 1) res[n]++;
}
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
ll comb(ll n, ll k) {
  if(k > n-k) k = n-k;
  ll ret = 1;
  rep(i, k) {
    (ret *= (n-i) % mod) %= mod;
    (ret *= modinv(i+1)) %= mod;
  }
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, k; cin >> n >> k;
  map<ll, int> res;
  prime_factorization(n, res);
  ll ans = 1;
  for(auto [_, c]: res) {
    (ans *= comb(c+k, c)) %= mod;
  }
  cout << ans << endk;
  return 0;
}
