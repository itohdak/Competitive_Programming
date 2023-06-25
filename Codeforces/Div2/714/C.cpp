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

vector<vector<ll>> dp(10, vector<ll>(200005));
void solve() {
  string s; cin >> s;
  int m; cin >> m;
  vector<int> cnt(10);
  for(char c: s) {
    cnt[c-'0']++;
  }
  ll ans = 0;
  rep(i, 10) {
    (ans += cnt[i] * dp[i][m]) %= mod;
  }
  cout << ans << endk;
}
void make() {
  rep(i, 10) dp[i][0] = 1;
  REP(j, 1, 200005) {
    rep(i, 10) {
      if(i == 9) {
        (dp[9][j] = dp[0][j-1] + dp[1][j-1]) %= mod;
      } else {
        dp[i][j] = dp[i+1][j-1];
      }
    }
  }
  // rep(i, 10) {
  //   rep(j, 10) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endk;
  // }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
