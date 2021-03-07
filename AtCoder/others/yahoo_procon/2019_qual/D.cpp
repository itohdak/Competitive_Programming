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
  vector<vector<ll>> dp(n+1, vector<ll>(5, longinf));
  rep(j, 5) dp[0][j] = 0;
  rep(i, n) {
    chmin(dp[i+1][0], dp[i][0]+A[i]);
    chmin(dp[i+1][1], dp[i][0]+(A[i]==0 ? 2 : A[i]%2));
    chmin(dp[i+1][2], dp[i][0]+(A[i]+1)%2);
    chmin(dp[i+1][3], dp[i][0]+(A[i]==0 ? 2 : A[i]%2));
    chmin(dp[i+1][4], dp[i][0]+A[i]);

    chmin(dp[i+1][1], dp[i][1]+(A[i]==0 ? 2 : A[i]%2));
    chmin(dp[i+1][2], dp[i][1]+(A[i]+1)%2);
    chmin(dp[i+1][3], dp[i][1]+(A[i]==0 ? 2 : A[i]%2));
    chmin(dp[i+1][4], dp[i][1]+A[i]);

    chmin(dp[i+1][2], dp[i][2]+(A[i]+1)%2);
    chmin(dp[i+1][3], dp[i][2]+(A[i]==0 ? 2 : A[i]%2));
    chmin(dp[i+1][4], dp[i][2]+A[i]);

    chmin(dp[i+1][3], dp[i][3]+(A[i]==0 ? 2 : A[i]%2));
    chmin(dp[i+1][4], dp[i][3]+A[i]);

    chmin(dp[i+1][4], dp[i][4]+A[i]);
  }
  cout << *min_element(all(dp[n])) << endk;
  return 0;
}
