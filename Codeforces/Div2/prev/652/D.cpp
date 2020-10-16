#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

const int max_n = 2000005;
vector<vector<ll>> dp;
void solve() {
  int n;
  cin >> n;
  cout << (max(dp[n][0], dp[n][1]) * 4) % mod << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  dp = vector<vector<ll>>(max(max_n+1, 3), vector<ll>(2));
  dp[1][0] = dp[1][1] = 0;
  dp[2][0] = dp[2][1] = 0;
  REP(i, 3, max_n+1) {
    dp[i][0] = 2 * max(dp[i-2][0], dp[i-2][1]) + max(dp[i-1][0], dp[i-1][1]);
    dp[i][1] = 2 * dp[i-2][0] + dp[i-1][0] + 1;
    dp[i][0] %= mod;
    dp[i][1] %= mod;
  }

  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
