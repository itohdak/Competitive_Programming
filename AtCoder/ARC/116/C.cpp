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

template<typename T>
vector<T> smallest_prime_factors(T n) {
  vector<T> spf(n + 1);
  for(int i=0; i<=n; i++) spf[i] = i;
  for(T i=2; i*i<=n; i++) {
    // 素数だったら
    if(spf[i] == i) {
      for(T j=i*i; j<=n; j+=i) {
        // iを持つ整数かつまだ素数が決まっていないなら
        if(spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
  return spf;
}

template<typename T>
vector<T> factorization(T x, vector<T>& spf) {
  vector<T> ret;
  while(x != 1) {
    ret.push_back(spf[x]);
    x /= spf[x];
  }
  sort(ret.begin(), ret.end());
  return ret;
}

constexpr ll MAX = 200005;
auto spf = smallest_prime_factors(MAX);

#define MAX_N 200500
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
  int n, m; cin >> n >> m;
  make();
  ll ans = 0;
  for(ll i=1; i<=m; i++) {
    auto ret = factorization(i, spf);
    map<ll, int> cnt;
    for(ll d: ret) cnt[d]++;
    ll tmp = 1;
    for(auto [_, c]: cnt) {
      (tmp *= comb(c+n-1, n-1)) %= mod;
    }
    (ans += tmp) %= mod;
  }
  cout << ans << endk;
  return 0;
}
