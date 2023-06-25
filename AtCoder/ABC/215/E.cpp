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
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(11, vector<ll>(1<<10)));
  dp[0][10][0] = 1;
  rep(i, n) {
    rep(j, 11) {
      rep(k, 1<<10) {
        int c = s[i]-'A';
        if(j == 10) {
          if(k == 0) (dp[i+1][c][1<<c] += dp[i][j][k]) %= mod;
        } else {
          if(!((k>>j)&1)) continue;
          if(c == j) {
            (dp[i+1][j][k] += dp[i][j][k]) %= mod;
          } else {
            if(!((k>>c)&1)) {
              (dp[i+1][c][k^(1<<c)] += dp[i][j][k]) %= mod;
            }
          }
        }
        (dp[i+1][j][k] += dp[i][j][k]) %= mod;
      }
    }
  }
  ll ans = 0;
  rep(i, 11) rep(j, 1<<10) if(j) (ans += dp[n][i][j]) %= mod;
  cout << ans << endk;
  return 0;
}
