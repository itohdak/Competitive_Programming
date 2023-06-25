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
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  vector<vector<ll>> dp(n, vector<ll>(2));
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    dp[cur][0] = dp[cur][1] = 1;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      (dp[cur][0] *= (dp[ne][0]+dp[ne][1])) %= mod;
      (dp[cur][1] *= dp[ne][0]) %= mod;
    }
  };
  dfs(dfs, 0, -1);
  cout << (dp[0][0]+dp[0][1])%mod << endk;
  return 0;
}
