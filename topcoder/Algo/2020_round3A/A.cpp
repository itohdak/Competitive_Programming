#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

class RectangularObstacle {
public:
  ll countReachable(int x1_, int x2_, int y1_, int y2_, int s_) {
    ll x1 = x1_, x2 = x2_, y1 = y1_, y2 = y2_, s = s_;
    if(y1 > s) {
      // cerr << "type 1" << "\n";
      return (s+1)*(s+1)+s*s;
    } else if(y2 > s) {
      // cerr << "type 2" << "\n";
      ll res = s*s+(2*s+1+2*(s-y1+1)+1)*y1/2;
      for(int y=y1; y<=s; y++) {
        res += 2*(s-y)+1-max(min(s-y, x2)-max(-s+y, x1)+1, 0LL);
      }
      return res;
    } else {
      // cerr << "type 3" << "\n";
      ll res = s*s+(2*s+1+2*(s-y1+1)+1)*y1/2;
      for(int y=y1; y<=y2; y++) {
        res += 2*(s-y)+1-max(min(s-y, x2)-max(-s+y, x1)+1, 0LL);
      }
      if(-(s-y2-1) < x1 && s-y2-1 > x2) {
        // cerr << "type 3-1" << "\n";
        res += (x1+s-y2-1)*(x1+s-y2-1);
        res += (s-y2-1-x2)*(s-y2-1-x2);
        if(2*(x1-1)+(s-y2-1) >= 2*(x2+1)-(s-y2-1)) {
          ll m = 2*(x1-1)+(s-y2-1) - (2*(x2+1)-(s-y2-1)) + 1;
          if(m%2) res -= ((m+1)/2)*((m+1)/2);
          else res -= (1+m/2)*(m/2);
        }
      } else if(-(s-y2-1) < x1) {
        // cerr << "type 3-2" << "\n";
        res += (x1+s-y2-1)*(x1+s-y2-1);
      } else if(s-y2-1 > x2) {
        // cerr << "type 3-3" << "\n";
        res += (s-y2-1-x2)*(s-y2-1-x2);
      }
      return res;
    }
  }
};

int main() {
  int x1, x2, y1, y2; ll s;
  cin >> x1 >> x2 >> y1 >> y2 >> s;
  cout << RectangularObstacle().countReachable(x1, x2, y1, y2, s) << "\n";
}
