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

ll op(ll a, ll b) {
  return a + b;
}
ll e() {
  return (ll)0;
}
ll mapping(ll f, ll x) {
  return f + x;
}
ll composition(ll f, ll g) {
  return f + g;
}
ll id() {
  return (ll)0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> A(q);
  map<int, set<int>> mp;
  map<pair<int, int>, ll> mp2;
  rep(k, q) {
    int t; cin >> t;
    if(t == 1) {
      int l, r, x; cin >> l >> r >> x;
      l--;
      A[k] = {t, l, r, x};
    } else if(t == 2) {
      int i, x; cin >> i >> x;
      i--;
      A[k] = {t, i, x, -1};
    } else {
      int i, j; cin >> i >> j;
      i--; j--;
      A[k] = {t, i, j, -1};
      mp[i].insert(j);
      mp2[{i, j}] = 0;
    }
  }
  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(m);
  rep(i, q) {
    auto [i1, i2, i3, i4] = A[i];
    if(i1 == 1) {
      seg.apply(i2, i3, i4);
    } else if(i1 == 2) {
      for(int c: mp[i2]) {
        mp2[{i2, c}] = i3 - seg.prod(c, c+1);
      }
    } else {
      cout << mp2[{i2, i3}] + seg.prod(i3, i3+1) << endk;
    }
  }
  return 0;
}
