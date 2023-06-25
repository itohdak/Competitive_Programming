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

void solve() {
  int e, w; cin >> e >> w;
  vector<vector<int>> X(e, vector<int>(w));
  rep(i, e) rep(j, w) cin >> X[i][j];
  if(e > 10) {
    cout << 0 << endk;
    return;
  }

  vector<int> cnt(w);
  map<vector<int>, vector<string>> mp;
  auto dfs = [&](auto dfs, string cur) -> void {
    mp[cnt].push_back(cur);
    rep(i, w) {
      if(cnt[i] == 3) continue;
      cnt[i]++;
      cur += char('a'+i);
      dfs(dfs, cur);
      cnt[i]--;
      cur.pop_back();
    }
  };
  dfs(dfs, "");

  vector<map<string, ll>> dp(e+1);
  dp[0][""] = 0;
  rep(i, e) {
    for(auto [from, cost]: dp[i]) {
      for(auto to: mp[X[i]]) {
        int l = 0;
        while(l < min(from.size(), to.size()) && from[l] == to[l]) l++;
        int need = from.size()-l + to.size()-l;
        if(dp[i+1].count(to)) chmin(dp[i+1][to], cost+need);
        else                  dp[i+1][to] = cost+need;
      }
    }
  }

  ll ans = longinf;
  for(auto [from, cost]: dp[e]) {
    chmin(ans, cost+from.size());
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
