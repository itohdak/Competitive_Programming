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

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  int _n;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : _n(n), f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int p, const Monoid &x) {
    assert(0 <= p && p < _n);
    seg[p + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int p, const Monoid &x) {
    assert(0 <= p && p < _n);
    p += sz;
    seg[p] = x;
    while(p >>= 1) {
      seg[p] = f(seg[2 * p + 0], seg[2 * p + 1]);
    }
  }

  Monoid query(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    Monoid L = M1, R = M1;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, seg[l++]);
      if(r & 1) R = f(seg[--r], R);
    }
    return f(L, R);
  }

  Monoid get(const int &p) const {
    assert(0 <= p && p < _n);
    return seg[p + sz];
  }
};

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
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  vector<int> B = A;
  sort(all(B));
  B.erase(unique(all(B)), end(B));
  auto id = [&](int v) {
    return lower_bound(all(B), v) - begin(B);
  };
  SegmentTree<mint> seg(n, [](mint a, mint b) { return a + b; }, 0);
  mint pw = 1;
  rep(i, n) pw *= 2;
  mint ans = 0;
  rep(i, n) {
    int j = id(A[i]);
    ans += seg.query(0, j+1) / pw;
    seg.update(j, seg.get(j)+pw);
    pw /= 2;
  }
  cout << ans/2 << endk;
  return 0;
}
