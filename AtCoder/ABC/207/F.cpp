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
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n+1, vector<ll>(3)));
  // 0: 警備されていない
  // 1: 配置されていて、警備されている
  // 2: 配置されていないが、警備されている
  vector<int> size(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    dp[cur][0][0] = 1;
    dp[cur][1][1] = 1;
    size[cur]++;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      vector<vector<ll>> merged(n+1, vector<ll>(3));
      rep(i, size[cur]+1) rep(istat, 3) rep(j, size[ne]+1) rep(jstat, 3) {
        if(istat == 0) {
          if(jstat == 0 || jstat == 2) {
            if(i+j > n) continue;
            (merged[i+j][0] += dp[cur][i][istat] * dp[ne][j][jstat]) %= mod;
          } else {
            if(i+j+1 > n) continue;
            (merged[i+j+1][2] += dp[cur][i][istat] * dp[ne][j][jstat]) %= mod;
          }
        } else if(istat == 1) {
          if(jstat == 0) {
            if(i+j+1 > n) continue;
            (merged[i+j+1][1] += dp[cur][i][istat] * dp[ne][j][jstat]) %= mod;
          } else {
            if(i+j > n) continue;
            (merged[i+j][1] += dp[cur][i][istat] * dp[ne][j][jstat]) %= mod;
          }
        } else {
          if(i+j > n) continue;
          (merged[i+j][2] += dp[cur][i][istat] * dp[ne][j][jstat]) %= mod;
        }
      }
      dp[cur] = merged;
      size[cur] += size[ne];
    }
  };
  dfs(dfs, 0, -1);
  rep(i, n+1) cout << accumulate(all(dp[0][i]), 0LL) % mod << endk;
  return 0;
}
