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
  ll a, b, c; cin >> a >> b >> c;
  ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  // ax + by + c = 0
  set<pair<ld, ld>> intersect;
  if((ld)(a*x1+b*min(y1, y2)+c)*(a*x1+b*max(y1, y2)+c)<=0) {
    intersect.insert({x1, -(ld)(a*x1+c)/b});
  }
  if((ld)(a*x2+b*min(y1, y2)+c)*(a*x2+b*max(y1, y2)+c)<=0) {
    intersect.insert({x2, -(ld)(a*x2+c)/b});
  }
  if((ld)(a*min(x1, x2)+b*y1+c)*(a*max(x1, x2)+b*y1+c)<=0) {
    intersect.insert({-(ld)(b*y1+c)/a, y1});
  }
  if((ld)(a*min(x1, x2)+b*y2+c)*(a*max(x1, x2)+b*y2+c)<=0) {
    intersect.insert({-(ld)(b*y2+c)/a, y2});
  }
  if(intersect.size() == 0) {
    cout << abs(x1-x2) + abs(y1-y2) << endk;
  } else if(intersect.size() == 2) {
    auto [p1, q1] = *intersect.begin();
    auto [p2, q2] = *intersect.rbegin();
    ld k1 = (q1-q2)/(p1-p2);
    ld k2 = (ld)(y1-y2)/(x1-x2);
    if(k1*k2 < 0) {
      cout << abs(x1-x2) + abs(y1-y2) << endk;
    } else {
      cout << fixed << setprecision(20) << abs(x1-x2) + abs(y1-y2) - abs(p1-p2) - abs(q1-q2) + sqrt((p1-p2)*(p1-p2)+(q1-q2)*(q1-q2)) << endk;
    }
  } else {
    assert(false);
  }
  return 0;
}
