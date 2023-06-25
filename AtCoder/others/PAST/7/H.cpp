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
  vector<int> A(n); rep(i, n) cin >> A[i];
  int sum = accumulate(all(A), 0);
  vector<vector<vector<ld>>> dp(n, vector<vector<ld>>(sum+1, vector<ld>(101, inf)));
  dp[0][0][0] = 0;
  rep(i, n-1) {
    rep(j, sum+1) {
      rep(k, 101) {
        rep(l, (i == n-2 ? 1 : 101)) {
          if(j+l > sum) break;
          chmin(dp[i+1][j+l][l], dp[i][j][k]+sqrt(1+(l-k)*(l-k)));
        }
      }
    }
  }
  cout << fixed << setprecision(10) << dp[n-1][sum][0] << endk;
  return 0;
}
