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

using mint = modint998244353;
struct S {
  mint val;
  int size;
};
struct F {
  mint mul, add;
};
S op(S a, S b) {
  return S{(a.val+b.val), a.size+b.size};
}
S e() {
  return S{0LL, 1};
}
S mapping(F f, S x) {
  return S{(f.mul*x.val+f.add*x.size), x.size};
}
F composition(F f, F g) {
  return F{f.mul*g.mul, f.mul*g.add+f.add};
}
F id() {
  return F{1LL, 0LL};
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  vector<S> init(n);
  rep(i, n) init[i] = {A[i], 1};
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
  rep(i, m) {
    int l, r, x; cin >> l >> r >> x;
    l--;
    seg.apply(l, r, {(mint)(r-l-1)/(r-l), (mint)x/(r-l)});
  }
  rep(i, n) {
    cout << seg.prod(i, i+1).val.val() << ' ';
  }
  cout << endk;
  return 0;
}
