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
  int h1, h2, h3, w1, w2, w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
  ll ans = 0;
  REP(i, 1, 31) REP(j, 1, 31) REP(k, 1, 31) REP(l, 1, 31) {
    // i j x
    // k l x
    // x x x
    int a13 = h1-i-j;
    int a23 = h2-k-l;
    int a31 = w1-i-k;
    int a32 = w2-j-l;
    int a331 = h3-a31-a32;
    int a332 = w3-a13-a23;
    if(a13 > 0 && a23 > 0 && a31 > 0 && a32 > 0 && a331 > 0 && a332 > 0 && a331 == a332) {
      ans++;
    }
  }
  cout << ans << endk;
  return 0;
}
