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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> dp(n, -n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    int tmp = 0;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      tmp += max(0, dp[ne]);
    }
    chmax(dp[cur], tmp + (A[cur] ? 1 : -1));
  };
  dfs(dfs, 0, -1);
  // cout << dp << endk;
  vector<int> ans(n);
  auto dfs2 = [&](auto dfs2, int cur, int par, int val) -> void {
    ans[cur] = dp[cur] + max(0, val);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs2(dfs2, ne, cur, dp[cur]-max(0, dp[ne])+max(0, val));
    }
  };
  dfs2(dfs2, 0, -1, 0);
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
