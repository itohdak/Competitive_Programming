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
  cout << fixed << setprecision(15);
  ll r, x1, y1, x2, y2; cin >> r >> x1 >> y1 >> x2 >> y2;
  ll dx = x1-x2, dy = y1-y2;
  ll d2 = dx*dx+dy*dy;
  if(d2 == 0) {
    cout << x1 << ' ' << y1-(ld)r/2 << ' ' << (ld)r/2 << endk;
  } else if(d2 < r*r) {
    ld d = sqrt(d2);
    ld vx = dx/d, vy = dy/d;
    ld ax = (x1+vx*r+x2)/2, ay = (y1+vy*r+y2)/2;
    ld ar = (r+d)/2;
    cout << ax << ' ' << ay << ' ' << ar << endk;
  } else {
    cout << x1 << ' ' << y1 << ' ' << r << endk;
  }
  return 0;
}
