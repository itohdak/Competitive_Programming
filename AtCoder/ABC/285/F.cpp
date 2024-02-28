#include <bits/stdc++.h>
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
  char mn, mx;
  bool ok;
};
S op(S a, S b) {
  return S{min(a.mn, b.mn), max(a.mx, b.mx), a.ok && b.ok && (a.mx<=b.mn)};
}
S e() {
  return S{'z', 'a', true};
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  int q; cin >> q;
  segtree<S, op, e> seg(n);
  vector<fenwick_tree<int>> cnt(26, fenwick_tree<int>(n));
  rep(i, n) {
    seg.set(i, S{s[i], s[i], true});
    cnt[s[i]-'a'].add(i, 1);
  }
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x; char c; cin >> x >> c;
      x--;
      seg.set(x, S{c, c, true});
      cnt[s[x]-'a'].add(x, -1);
      s[x] = c;
      cnt[s[x]-'a'].add(x, 1);
    } else {
      int l, r; cin >> l >> r;
      l--;
      bool ok = true;
      auto ret = seg.prod(l, r);
      ok &= ret.ok;
      for(char c=ret.mn+1; c<ret.mx; c++) {
        ok &= (cnt[c-'a'].sum(0, n) - cnt[c-'a'].sum(l, r) == 0);
      }
      cout << (ok ? "Yes" : "No") << endk;
    }
  }
  return 0;
}
