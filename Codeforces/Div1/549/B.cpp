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

class Doubling {
public:
  int N;
  int logK;
  vector<vector<int>> next;

  Doubling(int N, vector<int>& ini, ll K) {
    logK = log2(K);
    next = vector<vector<int>>(logK+1, vector<int>(N));
    rep(i, N) next[0][i] = ini[i];
    rep(k, logK) {
      rep(i, N) {
        next[k+1][i] = (next[k][i] == -1 ? -1 : next[k][next[k][i]]);
      }
    }
  }

  int query(int p, ll q) {
    for(int k=logK; k>=0; k--) {
      if(p == -1) break;
      if((q>>k)&1) p = next[k][p];
    }
    return p;
  }
};
template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<int> A(m); rep(i, m) cin >> A[i];
  map<int, int> next;
  rep(i, n) next[P[i]] = P[(i+1)%n];
  vector<set<int>> mp(n+1);
  rep(i, m) mp[A[i]].insert(i);
  for(auto& ele: mp) ele.insert(m);
  vector<int> ini(m+1);
  rep(i, m) ini[i] = *mp[next[A[i]]].lower_bound(i+1);
  ini[m] = m;
  Doubling dbl(m+1, ini, n);
  SegmentTree<int> seg(m, [](int a, int b) { return min(a, b); }, INT_MAX);
  rep(i, m) seg.update(i, dbl.query(i, n-1));
  // rep(i, m) cout << seg.query(0, i+1) << ' ';
  // cout << endk;
  vector<bool> ok(q);
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    // cout << l << ' ' << r << endk;
    // cout << seg.query(l, r) << endk;
    if(seg.query(l, r) < r) ok[i] = true;
  }
  rep(i, q) cout << ok[i];
  cout << endk;
  return 0;
}
