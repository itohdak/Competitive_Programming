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

ld e() {
  return 0;
}
ld op(ld n, ld m) {
  return n + m;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<int> A(k);
  segtree<ld, op, e> seg(n+1);
  segtree<ld, op, e> seg2(n+1);
  fenwick_tree<int> bit(n+1);
  rep(i, k) {
    cin >> A[i];
    A[i];
    bit.add(A[i], 1);
    seg2.set(A[i], 1);
  }
  for(int i=n-1; i>=0; i--) {
    if(bit.sum(i, i+1)) continue;
    seg.set(i, 1 + seg.prod(i+1, min(i+m+1, n+1)) / m);
    seg2.set(i, seg2.prod(i+1, min(i+m+1, n+1)) / m);
  }
  cout << fixed << setprecision(10);
  // rep(i, n+1) {
  //   cout << bit.sum(i, i+1) << ' ' << seg.prod(i, i+1) << ' ' << seg2.prod(i, i+1) << endk;
  // }
  if(1 == seg2.prod(0, 1)) cout << -1 << endk;
  else {
    ld ans = seg.prod(0, 1) / (1-seg2.prod(0, 1));
    cout << ans << endk;
  }
  return 0;
}
