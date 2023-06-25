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
  int r, c; cin >> r >> c;
  vector<string> ans(r*2+1, string(c*2+1, '.'));
  rep(i, r*2+1) rep(j, c*2+1) {
    if(i&1) {
      if(j&1) {
      } else {
        ans[i][j] = '|';
      }
    } else {
      if(j&1) {
        ans[i][j] = '-';
      } else {
        ans[i][j] = '+';
      }
    }
  }
  ans[0][0] = ans[0][1] = ans[1][0] = '.';
  rep(i, r*2+1) {
    cout << ans[i] << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ":" << endk;
    solve();
  }
  return 0;
}
