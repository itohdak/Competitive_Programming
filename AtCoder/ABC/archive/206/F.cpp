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
  int n; cin >> n;
  vector<pair<int, int>> seg(n);
  int mx = 100;
  for(auto& [l, r]: seg) {
    cin >> l >> r;
    l--; r--;
  }
  vector<vector<int>> dp(mx, vector<int>(mx, -1));
  auto dfs = [&](auto dfs, int l, int r) -> int {
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    set<int> st;
    for(auto [segl, segr]: seg) {
      if(l <= segl && segr <= r) {
        st.insert(dfs(dfs, l, segl)^dfs(dfs, segr, r));
      }
    }
    int mex = 0;
    while(st.count(mex)) mex++;
    return (dp[l][r] = mex);
  };
  cout << (dfs(dfs, 0, mx-1) ? "Alice" : "Bob") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
