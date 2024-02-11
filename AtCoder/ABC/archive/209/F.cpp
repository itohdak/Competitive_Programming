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
  vector<ll> H(n); rep(i, n) cin >> H[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1));
  vector<ll> cum(n+2);
  dp[1][1] = 1;
  REP(i, 1, n) { // i+1本目
    rep(j, n+1) cum[j+1] = (cum[j] + dp[i][j]) % mod;
    for(int j=1; j<=i+1; j++) { // j番目に切る
      int lb = 0, ub = 0;
      if(H[i-1] < H[i]) lb = j, ub = i;
      else if(H[i-1] == H[i]) lb = 1, ub = i;
      else if(H[i-1] > H[i]) lb = 1, ub = j-1;
      else assert(false);
      // for(int k=lb; k<=ub; k++) {
      //   (dp[i+1][j] += dp[i][k]) %= mod;
      // }
      dp[i+1][j] = (mod + cum[ub+1] - cum[lb]) % mod;
    }
  }
  ll ans = 0;
  rep(i, n+1) (ans += dp[n][i]) %= mod;
  cout << ans << endk;
  return 0;
}
