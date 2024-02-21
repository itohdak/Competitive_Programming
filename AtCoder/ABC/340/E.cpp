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
  return 0;
}
ll mapping(ll f, ll x) {
  return f + x;
}
ll composition(ll f, ll g) {
  return f + g;
}
ll id() {
  return 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(A);
  rep(i, m) {
    int b; cin >> b;
    ll c = seg.prod(b, b+1);
    seg.apply(b, b+1, -c);
    if(c/n > 0) {
      seg.apply(0, n, c/n);
    }
    int rem = c%n;
    if(b+1 < n) {
      seg.apply(b+1, min(b+rem+1, n), 1);
    }
    if(b+rem+1 > n) {
      seg.apply(0, b+rem+1-n, 1);
    }
  }
  rep(i, n) cout << seg.prod(i, i+1) << ' ';
  cout << endk;
  return 0;
}
