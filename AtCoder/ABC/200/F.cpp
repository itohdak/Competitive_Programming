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
  string s; cin >> s;
  ll k; cin >> k;
  int n = s.size();
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(4))); // i番目, 直前, (最初, 最後)
  vector<vector<vector<ll>>> dp2(n+1, vector<vector<ll>>(2, vector<ll>(4))); // i番目, 直前, (最初, 最後)
  if(s[0] == '0') {
    if(s[n-1] != '1') {
      dp2[1][0][0] = 1;
    } else if(s[n-1] != '0') {
      dp2[1][0][1] = 1;
    }
  } else if(s[0] == '1') {
    if(s[n-1] != '1') {
      dp2[1][1][2] = 1;
    } else if(s[n-1] != '0') {
      dp2[1][1][3] = 1;
    }
  } else {
    if(s[n-1] != '1') {
      dp2[1][0][0] = dp2[1][1][2] = 1;
    } else if(s[n-1] != '0') {
      dp2[1][0][1] = dp2[1][1][3] = 1;
    }
  }
  rep(i, n) {
    if(i == 0) continue;
    if(i == n-1) {
    } else {
      if(s[i] != '1') {
        rep(k, 4) {
          dp[i+1][0][k] = dp[i][0][k] + dp[i][1][k] + (k>>1&1 ? dp2[i][1][k] : 0);
          dp2[i+1][0][k] = dp2[i][0][k] + dp2[i][1][k];
        }
      } else if(s[0] != '0') {
        rep(k, 4) {
          dp[i+1][1][k] = dp[i][0][k] + dp[i][1][k] + (k>>1&1 ? 0 : dp2[i][0][k]);
          dp2[i+1][1][k] = dp2[i][0][k] + dp2[i][1][k];
        }
      }
    }
  }
  cout << dp[n] << endk;
  return 0;
}
