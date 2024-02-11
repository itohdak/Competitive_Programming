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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(200));
  dp[0][0].push_back({});
  rep(i, n) {
    rep(j, 200) {
      for(auto ele: dp[i][j]) {
        if(dp[i+1][j].size() >= 3) break;
        dp[i+1][j].push_back(ele);
      }
      for(auto ele: dp[i][j]) {
        if(dp[i+1][(j+A[i])%200].size() >= 3) break;
        ele.push_back(i);
        dp[i+1][(j+A[i])%200].push_back(ele);
      }
    }
  }
  // cout << dp[n] << endk;
  rep(i, 200) {
    vector<vector<int>> valid;
    for(auto ele: dp[n][i]) if(ele.size()) valid.push_back(ele);
    if(valid.size() >= 2) {
      cout << "YES" << endk;
      rep(j, 2) {
        cout << valid[j].size() << ' ';
        for(auto k: valid[j]) cout << k+1 << ' ';
        cout << endk;
      }
      return 0;
    }
  }
  cout << "NO" << endk;
  return 0;
}
