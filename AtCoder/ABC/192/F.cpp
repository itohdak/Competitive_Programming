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
  ll ans = longinf;
  for(int k=1; k<=n; k++) {
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(k, -longinf)));
    dp[0][0][0] = 0;
    rep(i, n) {
      rep(j, n+1) {
        rep(_k, k) {
          if(dp[i][j][_k] != -longinf) chmax(dp[i+1][j][_k], dp[i][j][_k]);
          if(j+1 < n+1 && dp[i][j][_k] != -longinf) chmax(dp[i+1][j+1][(_k+A[i])%k], dp[i][j][_k]+A[i]);
        }
      }
    }
    if(dp[n][k][x%k] != -longinf && (x - dp[n][k][x%k]) % k == 0) chmin(ans, (x - dp[n][k][x%k]) / k);
  }
  cout << ans << endk;
  return 0;
}
