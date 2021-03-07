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

ll modpow(ll a, ll N, ll mod=mod) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, a, b;
  int k;
  cin >> n >> a >> b >> k;
  string s; cin >> s;
  ll m = 1e9+9;
  ll sum = 0;
  ll atmp = modpow(a, n, m), btmp = 1;
  ll modinva = modinv(a, m);
  rep(i, k) {
    (sum += m + (s[i] == '-' ? -1 : 1) * (atmp * btmp % m)) %= m;
    (atmp *= modinva) %= m;
    (btmp *= b) %= m;
  }
  ll r = modpow(b, k, m) * modinv(modpow(a, k, m), m) % m;
  ll t = (n+1) / k;
  if(r == 1) {
    cout << sum * t % m << endk;
  } else {
    cout << sum * (modpow(r, t, m) - 1) % m * modinv(r - 1, m) % m << endk;
  }
  return 0;
}
