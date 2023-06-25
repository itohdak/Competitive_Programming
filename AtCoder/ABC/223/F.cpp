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

int op(int a, int b) {
  return min(a, b);
}
int e() {
  return inf;
}
int mapping(int f, int x) {
  return f+x;
}
int composition(int f, int g) {
  return f+g;
}
int id() {
  return 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> cum(n+1);
  rep(i, n) cum[i+1] = cum[i] + (s[i]=='(' ? 1 : -1);
  lazy_segtree<int, op, e, int, mapping, composition, id> seg(cum);
  rep(i, q) {
    int t, l, r; cin >> t >> l >> r;
    if(t == 1) {
      if(s[l-1] != s[r-1]) {
        if(s[l-1] == '(') {
          seg.apply(l, r, -2);
        } else {
          seg.apply(l, r, 2);
        }
        swap(s[l-1], s[r-1]);
      }
    } else {
      // rep(i, n+1) cout << seg.get(i) << ' '; cout << endk;
      int lbal = seg.get(l-1), rbal = seg.get(r);
      int mn = seg.prod(l-1, r);
      cout << (lbal == rbal && mn >= lbal ? "Yes" : "No") << endk;
    }
  }
  return 0;
}
