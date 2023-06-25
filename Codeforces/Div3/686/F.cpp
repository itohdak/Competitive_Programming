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
  int n; cin >> n;
  SegmentTree<int> seg(n, [](int a, int b) { return max(a, b); }, 0);
  vector<ll> A(n);
  rep(i, n) {
    cin >> A[i];
    seg.update(i, A[i]);
  }
  set<int> st;
  st.insert(-1);
  rep(i, n) st.insert(i);
  st.insert(n);
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    if(A[i] == A[j]) return i < j;
    else return A[i] > A[j];
  });
  int l = 0;
  while(l < n) {
    int r = l;
    while(r < n && A[id[r]] == A[id[l]]) r++;
    for(int i=l+1; i<r-1; i++) st.erase(id[i]);
    for(int i=l; i<r; i++) {
      int lo = *(--st.upper_bound(id[i]-1))+1;
      int hi = *(st.lower_bound(id[i]+1));
      if(0 < lo && hi < n && seg.query(0, lo) == A[id[i]] && seg.query(hi, n) == A[id[i]]) {
        cout << "YES" << endk;
        cout << lo << ' ' << hi-lo << ' ' << n-hi << endk;
        return;
      }
    }
    for(int i=l; i<r; i++) st.erase(id[i]);
    l = r;
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
