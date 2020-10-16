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
  vector<vector<ll>> dp(n+1, vector<ll>(10, -longinf));
  dp[0][0] = 0;
  rep(i, n) {
    int k; cin >> k;
    vector<ll> C(k), D(k);
    vector<vector<ll>> cost(4); // cards which costs i
    rep(j, k) {
      cin >> C[j] >> D[j];
      cost[C[j]].push_back(D[j]);
    }
    rep(j, 4) sort(all(cost[j]), greater<ll>());
    rep(j, 10) {
      // use no cards
      chmax(dp[i+1][j], dp[i][j]);
      // use 1 cards
      if(cost[1].size() >= 1) chmax(dp[i+1][(j+1)%10], dp[i][j] + cost[1][0] + (j==9 ? cost[1][0] : 0));
      if(cost[2].size() >= 1) chmax(dp[i+1][(j+1)%10], dp[i][j] + cost[2][0] + (j==9 ? cost[2][0] : 0));
      if(cost[3].size() >= 1) chmax(dp[i+1][(j+1)%10], dp[i][j] + cost[3][0] + (j==9 ? cost[3][0] : 0));
      // use 2 cards
      if(cost[1].size() >= 2)                        chmax(dp[i+1][(j+2)%10], dp[i][j] + cost[1][0] + cost[1][1] + (j>=8 ? cost[1][0] : 0));
      if(cost[1].size() >= 1 && cost[2].size() >= 1) chmax(dp[i+1][(j+2)%10], dp[i][j] + cost[1][0] + cost[2][0] + (j>=8 ? max(cost[1][0], cost[2][0]) : 0));
      // use 3 cards
      if(cost[1].size() >= 3) chmax(dp[i+1][(j+3)%10], dp[i][j] + cost[1][0] + cost[1][1] + cost[1][2] + (j>=7 ? cost[1][0] : 0));
    }
    // cout << dp << endl;
    // cout << cost << endl;
  }
  cout << *max_element(all(dp[n])) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
