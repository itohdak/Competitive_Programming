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
  int n, m; cin >> n >> m;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(n); rep(i, n) cin >> B[i];
  ll tmp = 1;
  ll ans = 0;
  ll modinvm = modinv(m), modinv2 = modinv(2);
  rep(i, n) {
    if(A[i] && B[i]) {
      if(A[i] > B[i]) {
        (ans += tmp) %= mod;
        break;
      } else if(A[i] == B[i]) {
        continue;
      } else {
        break;
      }
    } else if(A[i]) {
      (ans += tmp * (A[i]-1) % mod * modinvm % mod) %= mod;
      (tmp *= modinvm) %= mod;
    } else if(B[i]) {
      (ans += tmp * (m-B[i]) % mod * modinvm % mod) %= mod;
      (tmp *= modinvm) %= mod;
    } else {
      (ans += tmp * (m-1) % mod * modinvm % mod * modinv2 % mod) %= mod;
      (tmp *= modinvm) %= mod;
    }
  }
  cout << ans << endk;
  return 0;
}
