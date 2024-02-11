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
  int t; cin >> t;
  rep(i, t) {
    ll b, k, sx, sy, gx, gy;
    cin >> b >> k >> sx >> sy >> gx >> gy;
    map<pair<ll, ll>, ll> costS, costG;
    costS[{sx/b*b, sy}] = abs(sx-sx/b*b)*k;
    costS[{(sx/b+1)*b, sy}] = abs(sx-(sx/b+1)*b)*k;
    costS[{sx, sy/b*b}] = abs(sy-sy/b*b)*k;
    costS[{sx, (sy/b+1)*b}] = abs(sy-(sy/b+1)*b)*k;
    costG[{gx/b*b, gy}] = abs(gx-gx/b*b)*k;
    costG[{(gx/b+1)*b, gy}] = abs(gx-(gx/b+1)*b)*k;
    costG[{gx, gy/b*b}] = abs(gy-gy/b*b)*k;
    costG[{gx, (gy/b+1)*b}] = abs(gy-(gy/b+1)*b)*k;
    ll ans = longinf;
    for(auto [spos, scost]: costS) {
      for(auto [gpos, gcost]: costG) {
        auto [x1, y1] = spos;
        auto [x2, y2] = gpos;
        rep(i, 2) {
          rep(j, 2) {
            rep(k, 2) {
              rep(l, 2) {
                ll x1_ = (x1/b+i)*b;
                ll y1_ = (y1/b+j)*b;
                ll x2_ = (x2/b+k)*b;
                ll y2_ = (y2/b+l)*b;
                chmin(ans, scost + gcost + abs(x1_-x2_) + abs(y1_-y2_) + abs(x1_-x1) + abs(y1_-y1) + abs(x2_-x2) + abs(y2_-y2));
              }
            }
          }
        }
      }
    }
    chmin(ans, (abs(sx-gx) + abs(sy-gy))*k);
    cout << ans << endk;
  }
  return 0;
}
