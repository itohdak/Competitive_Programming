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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  reverse(all(A));
  vector<ll> cum(n+1); rep(i, n) cum[i+1] = cum[i] + A[i];
  int k = 0;
  while((k+1)*(k+2)/2 <= n) k++;
  vector<vector<bool>> dp(n+1, vector<bool>(k+1));
  vector<vector<ll>> sum(n+1, vector<ll>(k+1));
  dp[0][0] = true;
  sum[0][0] = longinf;
  rep(i, n) {
    rep(j, k+1) {
      if(!dp[i][j]) continue;
      dp[i+1][j] = true;
      chmax(sum[i+1][j], sum[i][j]);
      if(i+j+1 <= n && cum[i+j+1]-cum[i] < sum[i][j]) {
        dp[i+j+1][j+1] = true;
        chmax(sum[i+j+1][j+1], cum[i+j+1]-cum[i]);
      }
    }
  }
  int ans = 0;
  rep(i, k+1) if(dp[n][i]) ans = i;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
