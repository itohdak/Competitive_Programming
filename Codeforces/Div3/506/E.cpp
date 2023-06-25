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
  vector<vector<ll>> dp(n, vector<ll>(4, n));
  // 0: 置かれてない  塗られてない
  // 1: 置かれてない  塗られてる
  // 2: 置かれてる    塗られてない
  // 3: 置かれてる    塗られてる
  auto dfs = [&](auto dfs, int cur, int par, int depth) -> void {
    bool isLeaf = (par != -1 && G[cur].size() == 1);
    if(isLeaf) {
      dp[cur][0] = 0;
      if(depth <= 2) dp[cur][1] = 0;
      dp[cur][3] = 1;
    } else {
      ll cnt0 = 0, cnt1 = 0, cnt3 = 0;
      bool ok = false;
      vector<int> memo;
      for(int ne: G[cur]) {
        if(ne == par) continue;
        dfs(dfs, ne, cur, depth+1);
        cnt0 += dp[ne][1];
        int mn = *min_element(all(dp[ne]));
        cnt3 += mn;
        int less = min(dp[ne][1], dp[ne][3]);
        cnt1 += less;
        if(less == dp[ne][3]) {
          ok = true;
        } else {
          assert(less == dp[ne][1]);
          memo.push_back(dp[ne][3]-less);
        }
      }
      chmin(dp[cur][0], cnt0);
      sort(all(memo));
      chmin(dp[cur][1], (ok ? cnt1 : cnt1 + memo[0]));
      if(depth <= 2) chmin(dp[cur][1], cnt0);
      chmin(dp[cur][3], cnt3+1);
    }
  };
  dfs(dfs, 0, -1, 0);
  // rep(i, n) cout << dp[i] << endk;
  cout << *min_element(all(dp[0])) << endk;
  return 0;
}
