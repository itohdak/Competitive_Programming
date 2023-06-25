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
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<vector<int>> dp(n, vector<int>(2, inf));
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(par != -1 && G[cur].size() == 1) { // leaf
      dp[cur][0] = 0;
      dp[cur][1] = 1;
      return;
    }
    vector<int> memo0, memo1, diff;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      memo0.push_back(dp[ne][0]);
      memo1.push_back(dp[ne][1]);
      diff.push_back(dp[ne][0]-dp[ne][1]);
    }
    sort(all(diff));
    int sz = memo0.size();
    int sum = accumulate(all(memo1), 0);
    chmin(dp[cur][0], sum+diff[0]);
    chmin(dp[cur][1], sum+(sz>=2 ? diff[0]+diff[1] : diff[0])+1);
  };
  dfs(dfs, 0, -1);
  cout << dp << endk;
  cout << min(dp[0][0], dp[0][1]-1) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
