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
  ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
  if(r1 == r2 && c1 == c2) cout << 0 << endk;
  else if(r1+c1 == r2+c2) cout << 1 << endk;
  else if(r1-c1 == r2-c2) cout << 1 << endk;
  else if(abs(r1-r2) + abs(c1-c2) <= 3) cout << 1 << endk;
  else if((r1+c1)%2 == (r2+c2)%2) cout << 2 << endk;
  else {
    set<pair<int, int>> st;
    for(int i=-3; i<=3; i++) {
      for(int j=-3; j<=3; j++) {
        if(abs(i)+abs(j) > 3) continue;
        st.insert({r1+i, c1+j});
        int r3 = r1+i, c3 = c1+j;
        if(r3+c3 == r2+c2) {
          cout << 2 << endk;
          return 0;
        } else if(r3-c3 == r2-c2) {
          cout << 2 << endk;
          return 0;
        } else if(abs(r3-r2) + abs(c3-c2) <= 3) {
          cout << 2 << endk;
          return 0;
        }
      }
    }
    cout << 3 << endk;
  }
  // else if(abs((r1-c1)-(r2-c2)) <= 3) cout << 2 << endk;
  // else if(abs((r1+c1)-(r2+c2)) <= 3) cout << 2 << endk;
  // else {
  //   for(int i=-3; i<=3; i++) {
  //     for(int j=-3; j<=3; j++) {
  //       if(abs(i)+abs(j) > 3) continue;
  //       for(int ii=-3; ii<=3; ii++) {
  //         for(int jj=-3; jj<=3; jj++) {
  //           if(abs(ii)+abs(jj) > 3) continue;
  //           if(r2 == r1+i+ii && c2 == c1+j+jj) {
  //             cout << 2 << endk;
  //             return 0;
  //           }
  //         }
  //       }
  //     }
  //   }
  //   cout << 3 << endk;
  // }
  return 0;
}
