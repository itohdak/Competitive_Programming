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
  return max(a, b);
}
int e() {
  return (int)0;
}
int mapping(int f, int x) {
  return f + x;
}
int composition(int f, int g) {
  return f + g;
}
int id() {
  return (int)0;
}

int N = 400010;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, d, w; cin >> n >> d >> w;
  vector<int> T(n), X(n);
  rep(i, n) {
    cin >> T[i] >> X[i];
  }
  lazy_segtree<int, op, e, int, mapping, composition, id> seg(N);
  vector<pair<int, int>> Q;
  rep(i, n) {
    Q.push_back({T[i], X[i]});
    Q.push_back({T[i]+d, -X[i]});
  }
  sort(all(Q));
  int l = 0;
  ll ans = 0;
  while(l < Q.size()) {
    int r = l;
    while(r < Q.size() && Q[r].first == Q[l].first) {
      auto x = Q[r].second;
      if(x > 0) {
        seg.apply(x, x+w, 1);
      } else {
        seg.apply(-x, -x+w, -1);
      }
      r++;
    }
    chmax(ans, seg.prod(0, N));
    l = r;
  }
  cout << ans << endk;
  return 0;
}
