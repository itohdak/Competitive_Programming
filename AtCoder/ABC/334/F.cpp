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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  int sx, sy; cin >> sx >> sy;
  vector<int> X(n), Y(n);
  rep(i, n) {
    cin >> X[i] >> Y[i];
  }
  auto dist = [&](int x1, int y1, int x2, int y2) -> ld {
    ll dx = x1-x2, dy = y1-y2;
    return (ld)1*sqrtl(dx*dx+dy*dy);
  };
  SegmentTree<ld> seg(n+k-1, [](ld a, ld b) { return min(a, b); }, longinf);
  {
    ld d = dist(sx, sy, X[0], Y[0]);
    rep(i, k) seg.update(i, d);
  }
  ld cum = 0;
  rep(i, n-1) {
    ld d = dist(X[i], Y[i], X[i+1], Y[i+1]);
    cum += d;
    seg.update(k+i, seg.query(i, k+i) + dist(sx, sy, X[i], Y[i]) + dist(sx, sy, X[i+1], Y[i+1]) - d);
  }
  ld ans = seg.query(n-1, n+k-1) + cum + dist(sx, sy, X[n-1], Y[n-1]);
  cout << fixed << setprecision(10) << ans << endk;
  return 0;
}
