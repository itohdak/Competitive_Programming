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
  vector<vector<int>> pos(5001);
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    pos[A[i]].push_back(i);
  }
  vector<vector<bool>> dp(5001, vector<bool>(1<<13));
  vector<vector<int>> P(5001, vector<int>(1<<13, inf));
  dp[0][0] = true;
  P[0][0] = -1;
  rep(i, 5001) {
    if(i == 0) continue;
    rep(j, 1<<13) { // xor
      if(!dp[i-1][j]) continue;
      chmin(P[i][j], P[i-1][j]);
      dp[i][j] = true;
      auto itr = lower_bound(all(pos[i]), P[i-1][j]+1);
      if(itr == pos[i].end()) continue;
      int p = *itr;
      chmin(P[i][j^i], p);
      dp[i][j^i] = true;
    }
  }
  cout << accumulate(all(dp[5000]), 0) << endk;
  rep(j, 1<<13) if(dp[5000][j]) cout << j << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
