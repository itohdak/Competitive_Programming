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
  vector<ll> F(n+1);
  rep(i, n) cin >> F[i];
  vector<int> P(n);
  vector<vector<int>> G(n+1);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    G[(P[i]+n+1)%(n+1)].push_back(i);
  }
  vector<ll> dp(n+1);
  vector<ll> mn(n+1, inf);
  auto dfs = [&](auto dfs, int cur) -> void {
    vector<ll> mns, scores;
    for(int ne: G[cur]) {
      dfs(dfs, ne);
      mns.push_back(mn[ne]);
      scores.push_back(dp[ne]);
    }
    sort(all(mns));
    if(mns.empty()) {
      dp[cur] = F[cur];
      mn[cur] = F[cur];
    } else {
      dp[cur] = accumulate(all(scores), 0LL) + max(F[cur], mns[0]) - mns[0];
      mn[cur] = max(F[cur], mns[0]);
    }
  };
  dfs(dfs, n);
  cout << dp[n] << endk;
  // cout << dp << endk;
  // cout << mn << endk;
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
