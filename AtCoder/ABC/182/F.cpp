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
  int n; ll x; cin >> n >> x;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> cnt(n);
  {
    ll rem = x;
    rep(i, n) {
      if(i == n-1) cnt[i] = rem / A[i];
      else cnt[i] = (x % A[i+1]) / A[i];
    }
  }
  // cout << cnt << endk;
  vector<vector<ll>> dp(n, vector<ll>(2));
  dp[0][0] = 1;
  rep(i, n-1) {
    // 0
    if(cnt[i]) {
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][0];
    } else {
      dp[i+1][0] += dp[i][0];
    }
    // 1
    if(cnt[i]+1 < A[i+1]/A[i]) {
      dp[i+1][0] += dp[i][1];
      dp[i+1][1] += dp[i][1];
    } else {
      dp[i+1][1] += dp[i][1];
    }
  }
  // cout << dp << endk;
  cout << dp[n-1][0] + dp[n-1][1] << endk;
  return 0;
}
