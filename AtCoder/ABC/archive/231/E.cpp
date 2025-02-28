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
  ll BIG = 1000000000000000005LL;
  vector<ll> A(n+1, BIG); rep(i, n) cin >> A[i];
  vector<ll> D(n);
  rep(i, n) D[i] = x%A[i+1]/A[i];
  vector<vector<ll>> dp(n+1, vector<ll>(2, BIG));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, 2) {
      if(i < n-1 && D[i]+j >= A[i+1]/A[i]) {
        chmin(dp[i+1][1], dp[i][j]);
      } else {
        chmin(dp[i+1][0], dp[i][j]+(D[i]+j));
        if(i < n-1) chmin(dp[i+1][1], dp[i][j]+A[i+1]/A[i]-(D[i]+j));
      }
    }
  }
  // cout << D << endk;
  // cout << dp << endk;
  cout << *min_element(all(dp[n])) << endk;
  return 0;
}
