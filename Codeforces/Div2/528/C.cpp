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
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  set<pair<int, int>> st;
  if(xb < xa) {
    swap(xa, xb);
    swap(ya, yb);
  }
  if(xb >= xa) {
    if(yb < ya) {
      ya *= -1;
      yb *= -1;
      yc *= -1;
    }
    if(yb >= ya) {
      if(xa <= xc && xc <= xb && ya <= yc && yc <= yb) {
        for(int x=xa; x<=xc; x++) st.insert({x, ya});
        for(int y=ya; y<=yc; y++) st.insert({xc, y});
        for(int x=xc; x<=xb; x++) st.insert({x, yc});
        for(int y=yc; y<=yb; y++) st.insert({xb, y});
      } else if(xa <= xc && xc <= xb) {
        if(yc < ya) {
          for(int x=xa; x<=xb; x++) st.insert({x, ya});
          for(int y=ya; y<=yb; y++) st.insert({xb, y});
          for(int y=yc; y<=ya; y++) st.insert({xc, y});
        } else {
          for(int x=xa; x<=xb; x++) st.insert({x, yb});
          for(int y=ya; y<=yb; y++) st.insert({xa, y});
          for(int y=yb; y<=yc; y++) st.insert({xc, y});
        }
      } else if(ya <= yc && yc <= yb) {
         if(xc < xa) {
           for(int x=xa; x<=xb; x++) st.insert({x, yb});
           for(int y=ya; y<=yb; y++) st.insert({xa, y});
           for(int x=xc; x<=xa; x++) st.insert({x, yc});
         } else {
           for(int x=xa; x<=xb; x++) st.insert({x, ya});
           for(int y=ya; y<=yb; y++) st.insert({xb, y});
           for(int x=xb; x<=xc; x++) st.insert({x, yc});
         }
      } else {
        if(xc < xa) {
          if(yc < ya) {
            for(int x=xa; x<=xb; x++) st.insert({x, ya});
            for(int y=ya; y<=yb; y++) st.insert({xb, y});
            for(int x=xc; x<=xa; x++) st.insert({x, yc});
            for(int y=yc; y<=ya; y++) st.insert({xa, y});
          } else {
            for(int x=xa; x<=xb; x++) st.insert({x, yb});
            for(int y=ya; y<=yb; y++) st.insert({xa, y});
            for(int x=xc; x<=xa; x++) st.insert({x, yc});
            for(int y=yb; y<=yc; y++) st.insert({xa, y});
          }
        } else {
          if(yc < ya) {
            for(int x=xa; x<=xb; x++) st.insert({x, ya});
            for(int y=ya; y<=yb; y++) st.insert({xb, y});
            for(int x=xb; x<=xc; x++) st.insert({x, yc});
            for(int y=yc; y<=ya; y++) st.insert({xb, y});
          } else {
            for(int x=xa; x<=xb; x++) st.insert({x, yb});
            for(int y=ya; y<=yb; y++) st.insert({xa, y});
            for(int x=xb; x<=xc; x++) st.insert({x, yc});
            for(int y=yb; y<=yc; y++) st.insert({xb, y});
          }
        }
      }
    } else {
      assert(false);
    }
  } else {
    assert(false);
  }
  cout << st.size() << endk;
  for(auto [x, y]: st) cout << x << ' ' << abs(y) << endk;
  return 0;
}
