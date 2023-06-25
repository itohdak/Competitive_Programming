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
void solve() {
  int n; ll s; cin >> n >> s;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> cum(n+1); rep(i, n) cum[i+1] = cum[i] + A[i];
  SegmentTree<ll> segmin(n, [](ll a, ll b) { return min(a, b); }, LONG_LONG_MAX);
  rep(i, n) segmin.update(i, cum[i+1]);
  // cout << cum << endk;
  int mx = 0;
  int l = -1, r = -1;
  rep(i, n) {
    auto bsearch = [&](int l) {
      auto test = [&](int t) {
        ll minus = segmin.query(l, t) - cum[l];
        return s + minus >= 0;
      };
      int ok = l, ng = n+1;
      while(abs(ok-ng)>1) {
        int mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    int tmpr = bsearch(i);
    // cout << i << ' ' << tmpr << endk;
    if(mx < tmpr-i) {
      chmax(mx, tmpr-i);
      l = i, r = tmpr;
    }
  }
  if(mx == 0) cout << -1 << endk;
  else cout << l+1 << ' ' << r << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
