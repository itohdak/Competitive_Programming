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
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A), greater<ll>());
  // iまで見て、高橋君がj回操作をしたときの、青木君の抜く本数の最小値
  vector<vector<int>> dp(n+1, vector<int>(35, inf));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, 35) {
      if(j+1 < 35 && dp[i][j]+1 <= k) chmin(dp[i+1][j], dp[i][j]+1); // 操作しない
      int next = A.rend() - upper_bound(A.rbegin(), A.rend(), A[i]/2);
      chmin(dp[min(n, next)][j+1], dp[i][j]);
    }
  }
  // rep(i, n+1) cout << dp[i] << endk;
  rep(j, 35) {
    if(dp[n][j] < inf) {
      cout << j << ' ' << dp[n][j] << endk;
      break;
    }
  }
  return 0;
}
