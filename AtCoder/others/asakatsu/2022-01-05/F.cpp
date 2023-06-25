#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r, g, b; cin >> r >> g >> b;
  ll ans = longinf;
  auto cnt = [&](auto cnt, int l, int r, int c) {
    assert(l < r);
    if(r <= c) {
      return 1LL * (c-l + c-(r-1)) * (r-l) / 2;
    } else if(l < c) {
      return 1LL * cnt(cnt, l, c, c) + cnt(cnt, c, r, c);
    } else {
      return 1LL * (l-c + (r-1)-c) * (r-l) / 2;
    }
  };
  for(int i=-500; i<=500; i++) {
    int gl = i, gr = i+g;
    ll c = 0;
    c += cnt(cnt, gl, gr, 0);
    {
      ll tmp = longinf;
      for(int j=-500; j<=gl-r; j++) {
        chmin(tmp, cnt(cnt, j, j+r, -100));
      }
      c += tmp;
    }
    {
      ll tmp = longinf;
      for(int j=gr; j<=500; j++) {
        chmin(tmp, cnt(cnt, j, j+b, 100));
      }
      c += tmp;
    }
    chmin(ans, c);
  }
  cout << ans << endk;
  return 0;
}
