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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1));
  rep(i, n+1) REP(j, i, n+1) {
    if(i == j) dp[i][j] = 0;
    else dp[i][j] = (((j-i)^n)&1 ? longinf : -longinf);
  }
  for(int len=1; len<=n; len++) {
    rep(l, n) {
      int r = l+len;
      if(r > n) break;
      if((len^n)&1) {
        chmin(dp[l][r], dp[l+1][r]-A[l]);
        chmin(dp[l][r], dp[l][r-1]-A[r-1]);
      } else {
        chmax(dp[l][r], dp[l+1][r]+A[l]);
        chmax(dp[l][r], dp[l][r-1]+A[r-1]);
      }
    }
  }
  cout << dp[0][n] << endk;
  return 0;
}