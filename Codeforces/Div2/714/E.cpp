#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
#define MAX_N 100005
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
void solve() {
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll sum = accumulate(all(A), 0LL);
  if(sum % n != 0) {
    cout << 0 << endk;
    return;
  }
  ll ave = sum/n;
  vector<int> cnt(3);
  vector<map<ll, int>> mps(3);
  rep(i, n) {
    if(A[i] < ave) {
      cnt[0]++;
      mps[0][A[i]]++;
    } else if(A[i] == ave) {
      cnt[1]++;
      mps[1][A[i]]++;
    } else {
      cnt[2]++;
      mps[2][A[i]]++;
    }
  }
  if(cnt[1] == n) {
    cout << 1 << endk;
  } else if(cnt[0] == 1 || cnt[2] == 1) {
    ll ans = fac[n];
    rep(i, 3) for(auto [_, cnt]: mps[i]) {
      (ans *= finv[cnt]) %= mod;
    }
    cout << ans << endk;
  } else {
    ll ans = comb(n, cnt[1]);
    rep(i, 3) (ans *= fac[cnt[i]]) %= mod;
    rep(i, 3) for(auto [_, cnt]: mps[i]) {
      (ans *= finv[cnt]) %= mod;
    }
    (ans *= 2) %= mod;
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int T = 1;
  while(T--) solve();
  return 0;
}
