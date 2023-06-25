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
  int n; cin >> n;
  int ok = 0, ng = 1000000000;
  rep(i, n) {
    if(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      cout << mid << ' ' << 50 << endl;
      string col; cin >> col;
      (col == "white" ? ok : ng) = mid;
    } else {
      assert(i == 29);
      cout << ok << ' ' << 52 << endl;
      string col; cin >> col;
      if(col == "white") {
        cout << ok << ' ' << 53 << ' ' << ng << ' ' << 49 << endl;
      } else {
        cout << ok << ' ' << 51 << ' ' << ng << ' ' << 49 << endl;
      }
      return 0;
    }
  }
  cout << ok << ' ' << 49 << ' ' << ng << ' ' << 51 << endl;
  return 0;
}
