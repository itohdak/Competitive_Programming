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

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int m = (n+1)/2;
  vector<vector<mint>> dp(m+1, vector<mint>(9));
  dp[0][1*3+1] = 1;
  rep(i, m) {
    rep(j, 3) { // <, =, >
      rep(k, 3) { // <, =, >
        rep(l, 26) {
          int id1 = s[i]-'A';
          int id2 = s[n-1-i]-'A';
          int nj = 0, nk = 0;
          if(j == 0 || j == 2) {
            nj = j;
          } else if(j == 1) {
            if(l < id1)       nj = 0;
            else if(l == id1) nj = 1;
            else              nj = 2;
          }
          if(l < id2) {
            nk = 0;
          } else if(l == id2) {
            nk = k;
          } else {
            nk = 2;
          }
          dp[i+1][nj*3+nk] += dp[i][j*3+k];
        }
      }
    }
  }
  mint ans = 0;
  // cout << dp << endk;
  rep(j, 3) rep(k, 3) {
    int cur = j*3+k;
    if(j == 0) {
      ans += dp[m][cur];
    } else if(j == 1) {
      if(k == 0 || k == 1) ans += dp[m][cur];
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    solve();
  }
  return 0;
}
