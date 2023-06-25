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
};

template<typename T>
vector<vector<T>> matmul(vector<vector<T>>& A,
                         vector<vector<T>>& B) {
  assert(A[0].size() == B.size());
  int n = A.size();
  int m = B.size();
  int l = B[0].size();
  vector<vector<T>> ret(n, vector<T>(l));
  rep(i, n) rep(k, l) rep(j, m) ret[i][k] += A[i][j] * B[j][k];
  return ret;
}

template<typename T>
struct MatExp {

  vector<vector<T>> _trans;
  int _n;
  vector<vector<vector<T>>> M;
  int size = 60;

  MatExp(vector<vector<T>> trans): _trans(trans) {
    assert(_trans.size() == _trans[0].size());
    _n = _trans.size();
    init();
  }

  void init() {
    M.assign(size, vector<vector<T>>(_n, vector<T>(_n)));
    copy(all(_trans), M[0].begin());
    for(int i=1; i<size; i++) {
      M[i] = matmul(M[i-1], M[i-1]);
    }
  }

  vector<vector<T>> build(ll k) {
    vector<vector<T>> ret(_n, vector<T>(_n));
    rep(i, _n) ret[i][i] = 1;
    rep(i, size) {
      if((k>>i)&1) ret = matmul(ret, M[i]);
    }
    return ret;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll k; cin >> n >> k;
  vector<vector<mint>> A(n, vector<mint>(n));
  rep(i, n) rep(j, n) {
    int a; cin >> a;
    A[i][j] = a;
  }
  MatExp<mint> matexp(A);
  auto ret = matexp.build(k);
  mint ans = 0;
  rep(i, n) rep(j, n) {
    ans += ret[i][j];
  }
  cout << ans.value() << endk;
  return 0;
}
