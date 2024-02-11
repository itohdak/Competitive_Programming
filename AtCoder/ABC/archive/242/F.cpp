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

#define MAX_N 2000005
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n, m, b, w; cin >> n >> m >> b >> w;
  mint ans = 0;
  vector<vector<mint>> memo1(n+1, vector<mint>(m+1));
  vector<vector<mint>> memo2(n+1, vector<mint>(m+1));
  rep(i, n+1) rep(j, m+1) rep(k, i+1) rep(l, j+1) {
    // if((k+l)&1) memo1[i][j] -= (mint)1 * comb(i, k) * comb(j, l) * comb((i-k)*(j-l), b);
    // else        memo1[i][j] += (mint)1 * comb(i, k) * comb(j, l) * comb((i-k)*(j-l), b);
    if(((i-k)+(j-l))&1) memo1[i][j] -= (mint)1 * comb(i, k) * comb(j, l) * comb(k*l, b);
    else                memo1[i][j] += (mint)1 * comb(i, k) * comb(j, l) * comb(k*l, b);
  }
  rep(i, n+1) rep(j, m+1) rep(k, i+1) rep(l, j+1) {
    // if((k+l)&1) memo2[i][j] -= (mint)1 * comb(i, k) * comb(j, l) * comb((i-k)*(j-l), w);
    // else        memo2[i][j] += (mint)1 * comb(i, k) * comb(j, l) * comb((i-k)*(j-l), w);
    if(((i-k)+(j-l))&1) memo2[i][j] -= (mint)1 * comb(i, k) * comb(j, l) * comb(k*l, w);
    else                memo2[i][j] += (mint)1 * comb(i, k) * comb(j, l) * comb(k*l, w);
  }
  rep(i, n+1) rep(j, n+1-i) rep(k, m+1) rep(l, m+1-k) {
    if(i*k < b || j*l < w) continue;
    ans += (mint)1 * comb(n, i) * comb(n-i, j) * comb(m, k) * comb(m-k, l) * memo1[i][k] * memo2[j][l];
  }
  cout << ans << endk;
  return 0;
}
