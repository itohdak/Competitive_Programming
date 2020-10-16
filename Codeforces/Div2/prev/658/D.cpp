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

void solve() {
  int n; cin >> n;
  vector<ll> P(2*n); rep(i, 2*n) cin >> P[i];
  ll mx = 0;
  int l = 0;
  vector<int> v;
  rep(i, 2*n) {
    if(i!=0 && P[i]>mx) {
      v.push_back(i-l);
      l = i;
    }
    mx = max(P[i], mx);
  }
  v.push_back(2*n-l);
  int m = v.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1));
  dp[0][0] = 1;
  rep(i, m) {
    rep(j, n+1) {
      dp[i+1][j] += dp[i][j];
      if(j+v[i]<=n) dp[i+1][j+v[i]] += dp[i][j];
    }
  }
  cout << (dp[m][n] ? "YES" : "NO") << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
