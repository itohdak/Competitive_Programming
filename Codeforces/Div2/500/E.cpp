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
  vector<int> A(n); rep(i, n) cin >> A[i];
  int kmax = (n+1)/2;
  vector<vector<vector<int>>> dp(3, vector<vector<int>>(kmax+1, vector<int>(n+1, inf)));
  rep(i, n+1) dp[2][0][i] = 0;
  rep(i, n) {
    rep(j, kmax+1) {
      rep(k, 3) chmin(dp[min(2, k+1)][j][i+1], dp[k][j][i]); // do nothing
      if(j+1 < kmax+1) {
        chmin(dp[0][j+1][i+1], dp[2][j][i]+(i==0 ? 0 : max(0, A[i-1]-(A[i]-1)))+(i==n-1 ? 0 : max(0, A[i+1]-(A[i]-1))));
        if(i >= 2) chmin(dp[0][j+1][i+1], dp[1][j][i]+(i==0 ? 0 : max(0, min(A[i-1], A[i-2]-1)-(A[i]-1)))+(i==n-1 ? 0 : max(0, A[i+1]-(A[i]-1))));
      }
    }
  }
  for(int k=1; k<=kmax; k++) {
    int ans = inf;
    rep(i, 3) chmin(ans, dp[i][k][n]);
    cout << ans << ' ';
  }
  cout << endk;
  return 0;
}
