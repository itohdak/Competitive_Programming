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
  int sz, val;
};
struct F {
  int k;
};
S op(S a, S b) {
  return S{a.sz+b.sz, a.val+b.val};
}
S e() {
  return S{0, 0};
}
S mapping(F f, S a) {
  if(f.k >= 0) return S{a.sz, f.k*a.sz};
  else return a;
}
F composition(F f, F g) {
  if(f.k >= 0) return f;
  else return g;
}
F id() {
  return F{-1};
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q, x; cin >> n >> q >> x;
  vector<int> P(n);
  int pos = -1;
  rep(i, n) {
    cin >> P[i];
    if(P[i] == x) pos = i;
  }
  vector<S> init(n);
  rep(i, n) init[i] = S{1, (P[i] > x)};
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
  rep(i, q) {
    int c, l, r; cin >> c >> l >> r;
    l--;
    auto [sz, val] = seg.prod(l, r);
    seg.apply(l, r, F{0});
    if(c == 1) {
      seg.apply(r-val, r, F{1});
    } else {
      seg.apply(l, l+val, F{1});
    }
    if(l <= pos && pos < r) {
      if(c == 1) {
        pos = r-1-val;
      } else {
        pos = l+val;
      }
    }
    // rep(j, n) cout << seg.prod(j, j+1).val << ' '; cout << endk;
  }
  cout << pos+1 << endk;
  return 0;
}
