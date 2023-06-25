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
  vector<vector<int>> A(n, vector<int>(3));
  rep(i, n) rep(j, 3) cin >> A[i][j];
  vector<vector<ll>> dp(n+1, vector<ll>(3));
  rep(j, 3) dp[1][j] = A[0][j];
  REP(i, 1, n) {
    rep(j, 3) rep(k, 3) {
      if(j == k) continue;
      chmax(dp[i+1][k], dp[i][j]+A[i][k]);
    }
  }
  cout << *max_element(all(dp[n])) << endk;
  return 0;
}
