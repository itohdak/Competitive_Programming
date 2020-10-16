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
  int n; cin >> n;
  int big = 100000;
  int xmax=big, xmin=-big, ymax=big, ymin=-big;
  rep(i, n) {
    int x, y, f1, f2, f3, f4;
    cin >> x >> y >> f1 >> f2 >> f3 >> f4;
    if(!f1) chmax(xmin, x);
    if(!f2) chmin(ymax, y);
    if(!f3) chmin(xmax, x);
    if(!f4) chmax(ymin, y);
  }
  if(xmin <= xmax && ymin <= ymax) {
    cout << 1 << ' ' << xmin << ' ' << ymin << endk;
  } else {
    cout << 0 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
