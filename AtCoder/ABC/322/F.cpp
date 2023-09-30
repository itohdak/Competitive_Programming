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
  int mx0, mx1, l0, l1, r0, r1, len;
};
struct F {
  int flip;
};
S op(S a, S b) {
  return S{
    max({a.mx0, b.mx0, a.r0+b.l0}),
    max({a.mx1, b.mx1, a.r1+b.l1}),
    (a.len == a.l0 ? a.len+b.l0 : a.l0),
    (a.len == a.l1 ? a.len+b.l1 : a.l1),
    (b.len == b.r0 ? a.r0+b.len : b.r0),
    (b.len == b.r1 ? a.r1+b.len : b.r1),
    a.len + b.len
  };
}
S e() {
  return S{0, 0, 0, 0, 0, 0, 0};
}
S mapping(F f, S x) {
  if(f.flip == 0) return x;
  else return S{x.mx1, x.mx0, x.l1, x.l0, x.r1, x.r0, x.len};
}
F composition(F f, F g) {
  return F{f.flip^g.flip};
}
F id() {
  return F{0};
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<S> A(n);
  rep(i, n) {
    int j = s[i]-'0';
    A[i] = S{1-j, j, 1-j, j, 1-j, j, 1};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
  rep(i, q) {
    int t, l, r; cin >> t >> l >> r;
    l--;
    if(t == 1) {
      seg.apply(l, r, F{1});
    } else {
      // rep(j, n) {
      // 	cout << seg.prod(j, j+1).mx1;
      // }
      // cout << endk;
      cout << seg.prod(l, r).mx1 << endk;
    }
  }
  return 0;
}
