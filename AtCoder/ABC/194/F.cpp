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
int conv(char c) {
  if('A' <= c && c <= 'F') return c-'A'+10;
  else return c-'0';
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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  ll ans = 0;
  set<int> st;
  rep(i, n) {
    if(st.size() > k) break;
    rep(j, conv(s[i])) {
      int rem, remk;
      if(j == 0 && i == 0) {
        rem = 16;
        remk = k;
      } else if(st.count(j)) {
        int sz = st.size();
        rem = 16-sz;
        remk = k-sz;
      } else if(st.size() < k) {
        int sz = st.size();
        rem = 16-sz-1;
        remk = k-sz-1;
      }
      if(n-i-1 < remk) continue;
      if(i == n-1) (ans += 1) %= mod;
      else (ans += comb(rem, remk) * (modpow(k, n-i-1) - modpow(k-1, n-i-1) + mod) % mod) %= mod;
      cout << i << ' ' << j << ' ' << ans << endk;
    }
    st.insert(conv(s[i]));
  }
  cout << ans << endk;
  return 0;
}
