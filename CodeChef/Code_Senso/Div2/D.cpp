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

#define mint modint<1000000007>
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
  // GUNDIS
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  set<int> st;
  map<int, int> pos;
  vector<vector<int>> next(n, vector<int>(2));
  rrep(i, n) {
    if(pos.count(A[i])) {
      st.erase(pos[A[i]]);
    }
    pos[A[i]] = i;
    st.insert(i);
    auto itr = st.begin();
    if(st.size() >= 2) {
      itr++;
      next[i][0] = *itr+1;
    } else {
      next[i][0] = -1;
    }
    if(st.size() >= 3) {
      itr++;
      next[i][1] = *itr+1;
    } else {
      next[i][1] = -1;
    }
  }
  // cout << next << endk;
  auto comp = [](pair<int, int> p1, pair<int, int> p2) -> bool {
    ld log2 = logl(2), log3 = logl(3);
    return log2*p1.first+log3*p1.second < log2*p2.first+log3*p2.second;
  };
  vector<pair<int, int>> dp(n+1, {0, 0});
  rep(i, n) {
    if(comp(dp[i+1], dp[i])) dp[i+1] = dp[i];
    if(next[i][0] != -1) {
      auto ne = dp[i];
      ne.first++;
      if(comp(dp[next[i][0]], ne)) dp[next[i][0]] = ne;
    }
    if(next[i][1] != -1) {
      auto ne = dp[i];
      ne.second++;
      if(comp(dp[next[i][1]], ne)) dp[next[i][1]] = ne;
    }
  }
  // cout << dp << endk;
  mint ans = 1;
  rep(i, dp[n].first) ans *= 2;
  rep(i, dp[n].second) ans *= 3;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
