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
  vector<ll> sum(n);
  vector<int> child(n, 1);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      sum[cur] += sum[ne] + child[ne];
      child[cur] += child[ne];
    }
  };
  dfs(dfs, 0, -1);
  // cout << child << endk;
  // cout << sum << endk;
  vector<ll> ans(n);
  auto dfs2 = [&](auto dfs2, int cur, int par, ll val) -> void {
    ans[cur] = sum[cur] + val + (n-child[cur]);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      ll nextVal = val + (n-child[cur]) + (sum[cur]-sum[ne]-child[ne]);
      dfs2(dfs2, ne, cur, nextVal);
    }
  };
  dfs2(dfs2, 0, -1, 0);
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
