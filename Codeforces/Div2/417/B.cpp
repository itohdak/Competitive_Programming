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
  int n, m; cin >> n >> m;
  vector<string> S(n); rep(i, n) cin >> S[i];
  reverse(all(S));
  while(S.back() == string(m+2, '0')) {
    S.pop_back();
    n--;
  }
  if(n == 0) {
    cout << 0 << endk;
    return 0;
  }
  vector<vector<int>> dp(n+1, vector<int>(2, inf));
  dp[0][0] = 0;
  int ans = inf;
  rep(i, n) {
    int mx = 0;
    int mn = m+1;
    rep(j, m+2) {
      if(S[i][j] == '1') {
        chmax(mx, j);
        chmin(mn, j);
      }
    }
    if(i == n-1) {
      chmin(ans, dp[i][0]+mx+(n-1));
      chmin(ans, dp[i][1]+(m+1-mn)+(n-1));
    } else {
      chmin(dp[i+1][0], dp[i][0]+mx*2);
      chmin(dp[i+1][0], dp[i][1]+m+1);
      chmin(dp[i+1][1], dp[i][0]+m+1);
      chmin(dp[i+1][1], dp[i][1]+(m+1-mn)*2);
    }
  }
  cout << ans << endk;
  return 0;
}
