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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> A;
  map<tuple<int, int, int>, int> mp;
  rep(i, m+1) REP(j, i, m+1) REP(k, j, m+1) {
    if(i < m && i == j) continue;
    if(j < m && j == k) continue;
    mp[{i, j, k}] = A.size();
    A.push_back({i, j, k});
  }
  int M = A.size();
  vector<vector<mint>> dp(n+1, vector<mint>(M));
  dp[0][mp[{m, m, m}]] = 1;
  rep(i, n) {
    rep(j, M) {
      auto [a, b, c] = A[j];
      rep(k, m) {
        if(a >= k) {
          dp[i+1][mp[{k, b, c}]] += dp[i][j];
        } else if(b >= k) {
          dp[i+1][mp[{a, k, c}]] += dp[i][j];
        } else if(c >= k) {
          dp[i+1][mp[{a, b, k}]] += dp[i][j];
        }
      }
    }
  }
  // for(auto [a, b]: mp) {
  //   auto [v, u, w] = a;
  //   cout << v << ' ' << u << ' ' << w << ' ' << b << endk;
  // }
  // cout << dp << endk;
  // cout << accumulate(all(dp[n]), (mint)0) << endk;
  mint ans = 0;
  rep(i, M) {
    auto [a, b, c] = A[i];
    if(c < m) ans += dp[n][i];
  }
  cout << ans << endk;
  return 0;
}
