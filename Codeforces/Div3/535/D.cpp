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
  string s; cin >> s;
  vector<vector<int>> dp(n+1, vector<int>(3, inf));
  vector<vector<int>> par(n+1, vector<int>(3, -1));
  vector<char> col = {'R', 'G', 'B'};
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  rep(i, n) {
    rep(j, 3) {
      rep(k, 3) {
        if(j == k) continue;
        if(dp[i+1][k] > dp[i][j]+(s[i]!=col[k])) {
          dp[i+1][k] = dp[i][j]+(s[i]!=col[k]);
          par[i+1][k] = j;
        }
      }
    }
  }
  cout << *min_element(all(dp[n])) << endk;
  string ans;
  int tmp = min_element(all(dp[n])) - begin(dp[n]);
  int i = n;
  while(i) {
    ans += col[tmp];
    tmp = par[i][tmp];
    i--;
  }
  reverse(all(ans));
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
