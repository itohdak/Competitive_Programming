#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  for(int h=2; h<=2; h++) {
    for(int w=2; w<=8; w++) {
      ll cnt = 0;
      rep(i, 1<<(h*w)) {
        bool ok = true;
        rep(x, h-1) rep(y, w-1) {
          int sum = 0;
          rep(dx, 2) rep(dy, 2) {
            sum += (i>>((x+dx)*w+(y+dy)))&1;
          }
          if(sum != 2) ok = false;
        }
        if(ok) cnt++;
      }
      cout << h << ' ' << w << ' ' << cnt << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
