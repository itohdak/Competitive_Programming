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
  int n, k; cin >> n >> k;
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  vector<vector<int>> mp(n);
  rep(i, n) mp[A[i]].push_back(i);
  vector<vector<int>> dp(n+1, vector<int>(k+1, inf));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, k) {
      chmin(dp[i+1][j], dp[i][j]);
      auto itr = lower_bound(all(mp[i]), i+dp[i][j]);
      if(itr == mp[i].end()) continue;
      // cout << i << ' ' << j << ' ' << *itr << endk;
      chmin(dp[i+1][j+1], *itr-i);
    }
  }
  // cout << dp << endk;
  int ans = inf;
  rep(i, n+1) chmin(ans, dp[i][k]);
  cout << (ans == inf ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
