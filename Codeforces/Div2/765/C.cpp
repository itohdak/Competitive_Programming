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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, l, k; cin >> n >> l >> k;
  vector<int> D(n); rep(i, n) cin >> D[i];
  D.push_back(l);
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(k+1, inf)));
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, i+1) rep(m, k+1) dp[(i+1)&1][j][m] = inf;
    rep(j, i+1) {
      rep(m, k+1) {
        if(i == n-1) {
          chmin(dp[(i+1)&1][i+1][m], dp[i&1][j][m]+(D[i+1]-D[j])*A[j]);
        } else {
          if(m+1 < k+1) chmin(dp[(i+1)&1][j][m+1], dp[i&1][j][m]);
          chmin(dp[(i+1)&1][i+1][m], dp[i&1][j][m]+(D[i+1]-D[j])*A[j]);
        }
      }
    }
  }
  int ans = inf;
  rep(m, k+1) chmin(ans, dp[n&1][n][m]);
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
