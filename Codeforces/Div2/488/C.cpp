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
  vector<pair<int, int>> P(4), Q(4);
  rep(i, 4) cin >> P[i].first >> P[i].second;
  rep(i, 4) cin >> Q[i].first >> Q[i].second;
  bool ok = false;
  int mnPx = inf, mxPx = -inf, mnPy = inf, mxPy = -inf;
  rep(i, 4) {
    chmin(mnPx, P[i].first);
    chmax(mxPx, P[i].first);
    chmin(mnPy, P[i].second);
    chmax(mxPy, P[i].second);
  }
  int mnQx = inf, mxQx = -inf, mnQy = inf, mxQy = -inf;
  rep(i, 4) {
    auto [x, y] = Q[i];
    int xtrans = x+y;
    int ytrans = x-y;
    chmin(mnQx, xtrans);
    chmax(mxQx, xtrans);
    chmin(mnQy, ytrans);
    chmax(mxQy, ytrans);
  }
  for(int x=-100; x<=100; x++) {
    for(int y=-100; y<=100; y++) {
      if(mnPx <= x && x <= mxPx &&
         mnPy <= y && y <= mxPy) {
        int xtrans = x+y;
        int ytrans = x-y;
        if(mnQx <= xtrans && xtrans <= mxQx &&
           mnQy <= ytrans && ytrans <= mxQy) {
          ok = true;
        }
      }
    }
  }
  cout << (ok ? "YES" : "NO") << endk;
  return 0;
}
