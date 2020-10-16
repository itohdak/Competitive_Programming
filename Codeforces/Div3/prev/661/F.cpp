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
  vector<pair<int, int>> P(n);
  vector<int> X;
  rep(i, n) {
    cin >> P[i].first >> P[i].second;
    X.push_back(P[i].first);
    X.push_back(P[i].second);
  }
  sort(all(X));
  X.erase(unique(all(X)), end(X));
  vector<pair<int, int>> p(n);
  map<int, map<int, int>> mp;
  rep(i, n) {
    p[i].first = lower_bound(all(X), P[i].first) - begin(X);
    p[i].second = lower_bound(all(X), P[i].second) - begin(X);
    mp[p[i].first][p[i].second]++;
  }
  int m = X.size();
  vector<vector<int>> dp(m, vector<int>(m, -inf));
  auto dfs = [&](auto dfs, int l, int r) -> int {
    // メモ化されていれば，それを返す
    if(dp[l][r] != -inf) return dp[l][r];
    int ret = 0;
    // [l, r] があれば，それを選んで損はしない
    if(mp.count(l) && mp[l].count(r)) ret += mp[l][r];
    int mx = 0;
    if(mp.count(l)) {
      for(auto ele: mp[l]) {
        // nr >= r は不適
        if(ele.first >= r) break;
        // [l, nr] と [nr+1, r] を分割統治
        chmax(mx, dfs(dfs, l, ele.first) + dfs(dfs, ele.first+1, r));
      }
    }
    // [l+1, r] を探索
    if(l+1 <= r) chmax(mx, dfs(dfs, l+1, r));
    ret += mx;
    return dp[l][r] = ret;
  };
  cout << dfs(dfs, 0, m-1) << endk;
  // cout << X << endk;
  // cout << p << endk;
  // rep(i, m) cout << dp[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
