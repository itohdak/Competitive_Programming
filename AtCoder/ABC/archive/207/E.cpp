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
  vector<ll> sum(n+1); rep(i, n) sum[i+1] = sum[i] + A[i];
  vector<vector<ll>> dp(n+1, vector<ll>(n+1));
  dp[0][0] = 1;
  rep(i, n) {
    vector<vector<int>> rem(i+1);
    rep(j, n+1) rem[sum[j]%(i+1)].push_back(j);
    rep(j, i+1) {
      ll cum = 0;
      for(int k: rem[j]) {
        (dp[i+1][k] += cum) %= mod;
        (cum += dp[i][k]) %= mod;
      }
    }
  }
  ll ans = 0;
  rep(i, n+1) (ans += dp[i][n]) %= mod;
  cout << ans << endk;
  return 0;
}