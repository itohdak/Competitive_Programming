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
  int x, y; cin >> x >> y;
  vector<int> X(n), Y(n);
  rep(i, n) cin >> X[i] >> Y[i];
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(301, vector<int>(301, inf)));
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, 301) rep(k, 301) {
      chmin(dp[i+1][j][k], dp[i][j][k]);
      chmin(dp[i+1][min(300, j+X[i])][min(300, k+Y[i])], dp[i][j][k]+1);
    }
  }
  int ans = inf;
  REP(j, x, 301) REP(k, y, 301) {
    chmin(ans, dp[n][j][k]);
  }
  cout << (ans == inf ? -1 : ans) << endk;
  return 0;
}