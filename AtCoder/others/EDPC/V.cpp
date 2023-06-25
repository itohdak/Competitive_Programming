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
  int n; ll m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  vector<ll> dp(n);
  vector<vector<ll>> prodl(n), prodr(n);
  vector<vector<ll>> val(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    int child = (par == -1 ? G[cur].size() : G[cur].size()-1);
    val[cur] = vector<ll>(child);
    prodl[cur] = vector<ll>(child+1, 1);
    prodr[cur] = vector<ll>(child+1, 1);
    dp[cur] = 1;
    int i = 0;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      (dp[cur] *= (dp[ne]+1)) %= m;
      val[cur][i] = (dp[ne]+1);
      i++;
    }
    rep(i, child) prodl[cur][i+1] = prodl[cur][i] * val[cur][i] % m;
    rrep(i, child) prodr[cur][i] = prodr[cur][i+1] * val[cur][i] % m;
  };
  dfs(dfs, 0, -1);
  // cout << dp << endk;
  vector<ll> ans(n);
  auto dfs2 = [&](auto dfs2, int cur, int par, ll val) -> void {
    (ans[cur] = dp[cur] * (val+1)) %= m;
    int i = 0;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs2(dfs2, ne, cur, prodl[cur][i]*prodr[cur][i+1]%m*(val+1)%m);
      i++;
    }
  };
  dfs2(dfs2, 0, -1, 0);
  // cout << ans << endk;
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
