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

void solve() {
  int r; cin >> r;
  if(r > 100) {
    cout << 0 << endk;
    return;
  }
  set<pair<int, int>> st;
  for(int rr=0; rr<=r; rr++) {
    for(int x=-rr; x<=rr; x++) {
      int l = floor(sqrt(rr*rr-x*x)), r = l+1;
      int y = (sqrt(rr*rr-x*x)-l <= r-sqrt(rr*rr-x*x) ? l : r);
      st.insert({x, y});
      st.insert({x, -y});
      st.insert({y, x});
      st.insert({-y, x});
    }
  }
  // cout << st << endk;
  int cnt = 0;
  for(int x=-r; x<=r; x++) {
    for(int y=-r; y<=r; y++) {
      if(round(sqrt(x*x+y*y)) <= r && !st.count({x, y})) {
        // cout << x << ' ' << y << endk;
        cnt++;
      }
    }
  }
  cout << cnt << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
