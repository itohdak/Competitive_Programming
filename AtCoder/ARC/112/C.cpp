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
  vector<int> P(n, -1);
  vector<vector<int>> G(n);
  rep(i, n) {
    if(i) {
      cin >> P[i];
      P[i]--;
      G[P[i]].push_back(i);
    }
  }
  vector<int> dp(n);
  vector<int> sz(n, 1);
  auto dfs = [&](auto dfs, int cur) -> void {
    dp[cur] = 1;
    vector<tuple<int, int, int>> v;
    for(int ne: G[cur]) {
      dfs(dfs, ne);
      sz[cur] += sz[ne];
      if(sz[ne]%2 == 0) {
        if(dp[ne] < 0) {
          v.push_back({0, dp[ne], ne});
        } else {
          v.push_back({2, dp[ne], ne});
        }
      } else {
        v.push_back({1, dp[ne], ne});
      }
    }
    sort(all(v));
    int flag = 0;
    for(auto [f, d, ne]: v) {
      if(f == 0) {
        dp[cur] += d;
      } else if(f == 1) {
        if(!flag) dp[cur] += d;
        else      dp[cur] -= d;
        flag ^= 1;
      } else {
        if(!flag) dp[cur] += d;
        else      dp[cur] -= d;
      }
    }
  };
  dfs(dfs, 0);
  // cout << dp << endk;
  // cout << sz << endk;
  cout << (sz[0]+dp[0])/2 << endk;
  return 0;
}
