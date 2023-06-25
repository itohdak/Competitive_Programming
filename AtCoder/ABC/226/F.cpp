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

#define mint modint<mod2>
template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  friend ostream& operator<<(ostream& os, const modint& m) {
    return os << m.value();
  }
};
mint modpow(mint a, ll N) {
  mint ans = 1;
  mint tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp);
    (tmp *= tmp);
    N /= 2;
  }
  return ans;
}
#define MAX_N 100
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod2 - inv[mod2%i] * (mod2/i) % mod2;
    fac[i] = fac[i-1] * (ll)i % mod2;
    finv[i] = finv[i-1] * inv[i] % mod2;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod2;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r);
  ans = (ans * finv[r]) % mod2;
  return ans;
}
map<ll, int> prime_factorization(ll N) {
  map<ll, int> res;
  if(N == 1 || N == 0) return res;
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
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n, k; cin >> n >> k;
  vector<map<ll, int>> primes(n+1);
  rep(i, n+1) {
    if(i == 0) continue;
    primes[i] = prime_factorization(i);
  }
  mint ans = 0;
  vector<int> v = {0};
  auto solve = [&]() {
    map<ll, int> prime;
    rep(i, v.size()) {
      if(i == 0 || v[i] == 0) continue;
      for(auto [p, c]: primes[i]) {
        chmax(prime[p], c);
      }
    }
    mint lcm = 1;
    for(auto [p, c]: prime) {
      lcm *= modpow(p, c);
    }
    return lcm;
  };
  auto count = [&]() {
    mint ret = 1;
    int rem = n;
    rep(i, v.size()) {
      rep(j, v[i]) {
        ret *= comb(rem, i);
        ret *= fac[i-1];
        ret /= (j+1);
        rem -= i;
      }
    }
    // cout << ret << endk;
    return ret;
  };
  auto dfs = [&](auto dfs, int cur, int rem) -> void {
    if(rem == 0) {
      ans += modpow(solve(), k) * count();
      return;
    }
    if(cur > n) return;
    rep(i, n+1) {
      if(rem-cur*i < 0) break;
      v.push_back(i);
      dfs(dfs, cur+1, rem-cur*i);
      v.pop_back();
    }
  };
  dfs(dfs, 1, n);
  cout << ans << endk;
  return 0;
}
