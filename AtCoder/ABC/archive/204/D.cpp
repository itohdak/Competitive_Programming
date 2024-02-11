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
  vector<int> T(n); rep(i, n) cin >> T[i];
  sort(all(T));
  vector<vector<bool>> dp(n+1, vector<bool>(100001));
  dp[0][0] = true;
  rep(i, n) {
    rep(j, 100001) {
      if(!dp[i][j]) continue;
      dp[i+1][j] = true;
      if(j+T[i] < 100001) dp[i+1][j+T[i]] = true;
    }
  }
  int sum = accumulate(all(T), 0);
  int ans = inf;
  rep(i, 100001) {
    if(dp[n][i]) {
      chmin(ans, max(i, sum-i));
    }
  }
  cout << ans << endk;
  return 0;
}
