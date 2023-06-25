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
  auto bsearch1 = [&]() {
    int ok = 0, ng = n;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      cout << "? " << ok+1 << ' ' << mid << ' ' << 1 << ' ' << n << endl;
      int t; cin >> t;
      if(t == mid-ok) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    return ok;
  };
  auto bsearch2 = [&]() {
    int ok = 0, ng = n;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      cout << "? " << 1 << ' ' << n << ' ' << ok+1 << ' ' << mid << endl;
      int t; cin >> t;
      if(t == mid-ok) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    return ok;
  };
  int r = bsearch1();
  int c = bsearch2();
  cout << "! " << r+1 << ' ' << c+1 << endl;
  return 0;
}
