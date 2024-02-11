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
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  int mx = 200000;
  vector<int> cnt(mx);
  rep(i, n) cnt[A[i]]++;
  vector<vector<ll>> dp(mx+1, vector<ll>(4));
  dp[0][0] = 1;
  rep(i, mx) {
    rep(j, 4) {
      dp[i+1][j] += dp[i][j];
      if(j+1 < 4) {
        dp[i+1][j+1] += dp[i][j] * cnt[i];
      }
    }
  }
  cout << dp[mx][3] << endk;
  return 0;
}
