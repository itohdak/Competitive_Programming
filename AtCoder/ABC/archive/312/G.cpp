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
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> cnt(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    for(auto ne: G[cur]) {
      if(ne != par) {
	dfs(dfs, ne, cur);
	cnt[cur] += cnt[ne];
      }
    }
    cnt[cur]++;
  };
  dfs(dfs, 0, -1);
  // cout << cnt << endk;
  ll ans = 0;
  auto dfs2 = [&](auto dfs2, int cur, int par, int val) -> void {
    auto dp = [&](vector<int> C) {
      int m = C.size();
      vector<vector<ll>> DP(m+1, vector<ll>(4));
      DP[0][0] = 1;
      rep(i, m) {
	rep(j, 4) {
	  DP[i+1][j] += DP[i][j];
	  if(j+1 < 4) DP[i+1][j+1] += DP[i][j] * C[i];
	}
      }
      return DP[m][3];
    };
    vector<int> C;
    for(auto ne: G[cur]) {
      if(ne != par) C.push_back(cnt[ne]);
    }
    C.push_back(val);
    auto ret = dp(C);
    // cout << cur << ": " << ret << endk;
    // cout << C << endk;
    ans += ret;
    for(auto ne: G[cur]) {
      if(ne != par) {
	dfs2(dfs2, ne, cur, val+cnt[cur]-cnt[ne]);
      }
    }
  };
  dfs2(dfs2, 0, -1, 0);
  cout << ans << endk;
  return 0;
}
