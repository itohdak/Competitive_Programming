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
  int n, q; cin >> n >> q;
  int hanten1 = 0, hanten2 = 0;
  int kaiten = 0;
  int xm = n/2, ym = n/2;
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      rep(i, kaiten) {
      }
      //  0 1
      // -1 0
    } else if(t == 2) {
      char c; cin >> c;
      if(c == 'A') {
        if(hanten1^hanten2) {
          kaiten = (kaiten+3)%4;
        } else {
          kaiten = (kaiten+1)%4;
        }
      } else {
        if(hanten1^hanten2) {
          kaiten = (kaiten+1)%4;
        } else {
          kaiten = (kaiten+3)%4;
        }
      }
    } else {
      char c; cin >> c;
      if(c == 'A') {
        if(kaiten % 2 == 0) {
          hanten1 ^= 1;
        } else {
          hanten2 ^= 1;
        }
      } else {
        if(kaiten % 2 == 0) {
          hanten2 ^= 1;
        } else {
          hanten1 ^= 1;
        }
      }
    }
  }
  return 0;
}
