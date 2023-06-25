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

void solve() {
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<deque<int>> pos(n+1);
  rep(i, n) pos[A[i]].push_back(i);
  SegmentTree<bool> seg(n+1, [](bool a, bool b) { return a & b; }, 1);
  SegmentTree<int> seg2(n+1, [](int a, int b) { return max(a, b); }, -1);
  rep(i, n+1) {
    if(pos[i].size()) {
      seg.update(i, 1);
      seg2.update(i, pos[i].front());
    } else {
      seg.update(i, 0);
    }
  }
  vector<int> ans;
  int i = 0;
  while(i < n) {
    auto bsearch = [&]() {
      int ok = -1, ng = n+1;
      while(abs(ok-ng)>1) {
        int mid = (ok+ng)/2;
        (seg.query(0, mid+1) ? ok : ng) = mid;
      }
      return ok;
    };
    auto ret = bsearch();
    auto next = max(i, seg2.query(0, ret+1));
    ans.push_back(ret+1);
    while(i <= next) {
      assert(i == pos[A[i]].front());
      pos[A[i]].pop_front();
      if(pos[A[i]].size() == 0) seg.update(A[i], 0);
      else seg2.update(A[i], pos[A[i]].front());
      i++;
    }
  }
  cout << ans.size() << endk;
  for(int a: ans) cout << a << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
