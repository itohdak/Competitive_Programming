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
  int n; cin >> n;
  vector<int> P(n), Q(n);
  rep(i, n) cin >> P[i];
  rep(i, n) cin >> Q[i];
  vector<vector<mint>> dp0(n+1, vector<mint>(2)), dp1(n+1, vector<mint>(2));
  dp0[0][0] = dp1[0][1] = 1;
  rep(i, n) {
    rep(j, 2) {
      if(j == 0) {
        dp0[i+1][1] += dp0[i][j];
        dp1[i+1][1] += dp1[i][j];
      } else {
        dp0[i+1][0] += dp0[i][j];
        dp0[i+1][1] += dp0[i][j];
        dp1[i+1][0] += dp1[i][j];
        dp1[i+1][1] += dp1[i][j];
      }
    }
  }
  auto f = [&](int n) -> mint {
    return dp0[n-1][1] + dp1[n-1][0] + dp1[n-1][1];
  };
  // cout << dp0 << endk;
  // cout << dp1 << endk;
  vector<vector<int>> G(n);
  rep(i, n) {
    P[i]--;
    Q[i]--;
  }
  rep(i, n) G[P[i]].push_back(Q[i]);
  vector<bool> done(n);
  mint ans = 1;
  rep(i, n) {
    if(done[i]) continue;
    int cnt = 0;
    int cur = i;
    while(!done[cur]) {
      done[cur] = true;
      cnt++;
      cur = G[cur][0];
    }
    // cout << cnt << ' ' << f(cnt) << endk;
    ans *= f(cnt);
  }
  cout << ans << endk;
  return 0;
}
