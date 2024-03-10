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
  string t; cin >> t;
  int n; cin >> n;
  vector<vector<string>> S(n);
  rep(i, n) {
    int a; cin >> a;
    S[i] = vector<string>(a);
    rep(j, a) cin >> S[i][j];
  }
  int m = t.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, m+1) {
      chmin(dp[i+1][j], dp[i][j]);
      rep(k, S[i].size()) {
        if(m-j < S[i][k].size()) continue;
        if(t.substr(j, S[i][k].size()) == S[i][k]) {
          chmin(dp[i+1][j+S[i][k].size()], dp[i][j]+1);
        }
      }
    }
  }
  cout << (dp[n][m]==inf ? -1 : dp[n][m]) << endk;
  return 0;
}
