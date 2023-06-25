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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> preCalc(n);
  vector<ll> modpow_m_1(n+5);
  vector<ll> modpow_m(n+5);
  rep(i, n+5) {
    modpow_m_1[i] = modpow(m-1, i);
    modpow_m[i] = modpow(m, i);
  }
  rep(i, n) rep(j, m) (preCalc[i] += (modpow_m_1[i] - modpow(m-j-1, i) + mod) % mod) %= mod;
  ll ans = 0;
  rep(l, n) REP(r, l+1, n) (ans += modpow_m[n-(r-l+1)] * preCalc[r-l-1] % mod) %= mod;
  (ans += (modpow_m[n] - modpow_m_1[n] + mod) % mod * m % mod) %= mod;
  cout << ans << endk;
  return 0;
}
