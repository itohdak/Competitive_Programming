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
  string n; cin >> n;
  int m; cin >> m;
  vector<int> C(m);
  rep(i, m) cin >> C[i];
  vector<mint> pw(n.size()+1);
  pw[0] = 1;
  rep(i, n.size()) pw[i+1] = pw[i] * 10;
  vector<vector<vector<mint>>> dp(n.size()+1, vector<vector<mint>>(2, vector<mint>(1<<10)));
  vector<vector<vector<mint>>> cnt(n.size()+1, vector<vector<mint>>(2, vector<mint>(1<<10)));
  cnt[0][0][0] = 1;
  rep(i, n.size()) {
    rep(j, 2) {
      rep(k, 1<<10) {
        if(j == 0) {
          rep(l, 10) {
            if(l <= n[i]-'0') {
              dp[i+1][j|(l < n[i]-'0')][k|1<<l] += dp[i][j][k]*10 + pw[n.size()-1-i]*l*cnt[i][j][k];
              cnt[i+1][j|(l < n[i]-'0')][k|1<<l] += cnt[i][j][k];
            }
          }
        } else {
          rep(l, 10) {
            dp[i+1][j][k|1<<l] += dp[i][j][k]*10 + pw[n.size()-1-i]*l*cnt[i][j][k];
            cnt[i+1][j][k|1<<l] += cnt[i][j][k];
          }
        }
      }
    }
  }
  int tmp = 0;
  rep(i, m) tmp ^= 1<<C[i];
  cout << dp[n.size()][0][tmp] + dp[n.size()][1][tmp] << endk;
  cout << cnt[n.size()][0][tmp] + cnt[n.size()][1][tmp] << endk;
  return 0;
}
