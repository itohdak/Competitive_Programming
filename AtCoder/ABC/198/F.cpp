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
ll comb(ll n, ll k) {
  if(n < k) return 0;
  ll bunshi = 1;
  ll bunbo = 1;
  rep(i, k) {
    (bunshi *= (n-i)) %= mod;
    (bunbo *= (i+1)) %= mod;
  }
  return bunshi * modinv(bunbo) % mod;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll s; cin >> s;
  ll ans = 0;
  // 6
  (ans += comb(s-21, 5) * 180) %= mod;
  // 5
  (ans += comb(s-15, 4));
  return 0;
}
