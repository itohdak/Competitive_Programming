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

vector<int> make(ll v) {
  vector<int> D;
  while(v) {
    D.push_back(v%10);
    v /= 10;
  }
  return D;
}
ll dp[2][13][120][120];
ll DP(ll v) {
  auto D = make(v);
  reverse(all(D));
  int n = D.size();
  ll ret = 0;
  for(int sum=1; sum<=9*n; sum++) {
    vector<vector<vector<vector<ll>>>> dp(3, vector<vector<vector<ll>>>(n+1, vector<vector<ll>>(sum+1, vector<ll>(sum))));
    // 0: 0: not started, 1: started but equal, 2: started and lower
    // 1: index
    // 2: sum
    // 3: rem of prod mod sum
    dp[0][0][0][0] = 1;
    rep(i, n) {
      REP(j, max(0, sum-9*(n-i)), sum+1) {
        rep(k, sum) {
          rep(l, 10) {
            if(l == 0) {
              dp[0][i+1][j][k] += dp[0][i][j][k];
            } else { // l > 0
              // t: 0
              if(i > 0) {
                if(j+l <= sum) dp[2][i+1][j+l][l%sum] += dp[0][i][j][k];
              } else {
                if(l < D[i]) {
                  if(j+l <= sum) dp[2][i+1][j+l][l%sum] += dp[0][i][j][k];
                } else if(l == D[i]) {
                  if(j+l <= sum) dp[1][i+1][j+l][l%sum] += dp[0][i][j][k];
                }
              }
            }
            // t: 1
            if(l < D[i]) {
              if(j+l <= sum) dp[2][i+1][j+l][k*l%sum] += dp[1][i][j][k];
            } else if(l == D[i]) {
              if(j+l <= sum) dp[1][i+1][j+l][k*l%sum] += dp[1][i][j][k];
            }
            // t: 2
            if(j+l <= sum) dp[2][i+1][j+l][k*l%sum] += dp[2][i][j][k];
          }
        }
      }
    }
    ret += dp[1][n][sum][0] + dp[2][n][sum][0];
  }
  return ret;
}
void solve() {
  ll a, b; cin >> a >> b;
  cout << DP(b)-DP(a-1) << endk;
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
