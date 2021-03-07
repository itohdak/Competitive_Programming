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
  ll x, y; cin >> x >> y;
  vector<ll> C(7); rep(i, 6) cin >> C[i+1];
  if(x >= 0) {
    if(y >= 0) {
      if(abs(x) >= abs(y)) { // 1
        cout << min({
            C[6] * x + C[2] * y,
            C[1] * x + C[5] * (x-y),
            C[1] * y + C[6] * (x-y)
          }) << endk;
      } else { // 2
        cout << min({
            C[6] * x + C[2] * y,
            C[1] * x + C[2] * (y-x),
            C[1] * y + C[3] * (y-x)
          }) << endk;
      }
    } else {
      if(abs(x) >= abs(y)) { // 3
        cout << min({
            C[6] * x + C[5] * (-y),
            C[1] * x + C[5] * (x-y),
            C[4] * (-y) + C[6] * (x-y)
          }) << endk;
      } else { // 4
        cout << min({
            C[6] * x + C[5] * (-y),
            C[1] * x + C[5] * (x-y),
            C[4] * (-y) + C[6] * (x-y)
          }) << endk;
      }
    }
  } else {
    if(y >= 0) {
      if(abs(x) >= abs(y)) { // 5
        cout << min({
            C[3] * (-x) + C[2] * y,
            C[4] * (-x) + C[2] * (y-x),
            C[1] * y + C[3] * (y-x)
          }) << endk;
      } else { // 6
        cout << min({
            C[3] * (-x) + C[2] * y,
            C[4] * (-x) + C[2] * (y-x),
            C[1] * y + C[3] * (y-x)
          }) << endk;
      }
    } else {
      if(abs(x) >= abs(y)) { // 7
        cout << min({
            C[3] * (-x) + C[5] * (-y),
            C[4] * (-x) + C[2] * (y-x),
            C[4] * (-y) + C[3] * (y-x)
          }) << endk;
      } else { // 8
        cout << min({
            C[3] * (-x) + C[5] * (-y),
            C[4] * (-x) + C[5] * (x-y),
            C[4] * (-y) + C[6] * (x-y)
          }) << endk;
      }
    }
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
