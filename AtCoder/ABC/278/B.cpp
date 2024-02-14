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
  int h, m; cin >> h >> m;
  while(1) {
    int h1 = h/10, h2 = h%10;
    int m1 = m/10, m2 = m%10;
    if(h1*10+m1 < 24 && h2*10+m2 < 60) {
      cout << h << ' ' << m << endk;
      break;
    }
    m++;
    if(m == 60) {
      m = 0;
      h++;
      if(h == 24) {
        h = 0;
      }
    }
  }
  return 0;
}
