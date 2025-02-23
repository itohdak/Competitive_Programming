#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

struct S {
  int mn;
  int mx;
};
struct F {
  int add;
};
S op(S a, S b) {
  return S{min(a.mn, b.mn), max(a.mx, b.mx)};
}
S e() {
  return S{inf, 0};
}
S mapping(F f, S x) {
  return S{x.mn+f.add, x.mx+f.add};
}
F composition(F f, F g) {
  return F{f.add+g.add};
}
F id() {
  return F{0};
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int M = 500001;
  vector<S> init(M);
  rep(i, M) init[i] = S{i, i};
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
  rep(i, n) {
    int l, r; cin >> l >> r;
    r++;
    int re = seg.max_right(0, [&](S x) {
      return x.mx < r;
    });
    int le = seg.min_left(M, [&](S x) {
      return x.mn >= l;
    });
    seg.apply(le, re, F{1});
  }
  int q; cin >> q;
  rep(i, q) {
    int x; cin >> x;
    cout << seg.prod(x, x+1).mn << endk;
  }
  return 0;
}
