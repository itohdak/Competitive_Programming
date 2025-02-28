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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(n); rep(i, n) cin >> B[i];
  vector<vector<bool>> dp(n, vector<bool>(2));
  dp[0][0] = dp[0][1] = true;
  rep(i, n-1) {
    if(dp[i][0]) {
      if(abs(A[i]-A[i+1]) <= k) {
        dp[i+1][0] = true;
      }
      if(abs(A[i]-B[i+1]) <= k) {
        dp[i+1][1] = true;
      }
    }
    if(dp[i][1]) {
      if(abs(B[i]-A[i+1]) <= k) {
        dp[i+1][0] = true;
      }
      if(abs(B[i]-B[i+1]) <= k) {
        dp[i+1][1] = true;
      }
    }
  }
  cout << (dp[n-1][0]|dp[n-1][1] ? "Yes" : "No") << endk;
  return 0;
}
