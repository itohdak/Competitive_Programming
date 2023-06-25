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

void find_divisor(ll N, vector<int>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> P(n+1);
  vector<vector<int>> div(n);
  rep(i, n) {
    find_divisor(A[i], div[i]);
    for(int d: div[i]) {
      if(d > n) break;
      P[d].push_back(i);
    }
  }
  // vector<vector<ll>> dp(n+1);
  vector<ll> dp2(1, 1);
  P[0].push_back(-1);
  // rep(i, n+1) dp[i].assign(P[i].size(), 0);
  // dp[0][0] = 1;
  ll ans = 0;
  // cout << P << endl;
  // cout << dp << endl;
  rep(i, n) {
    vector<ll> next(P[i+1].size());
    rep(j, P[i].size()) {
      int ne = lower_bound(all(P[i+1]), P[i][j]+1) - begin(P[i+1]);
      if(ne == P[i+1].size()) continue;
      // (dp[i+1][ne] += dp[i][j]) %= mod;
      (next[ne] += dp2[j]) %= mod;
    }
    rep(j, P[i+1].size()-1) {
      // (dp[i+1][j+1] += dp[i+1][j]) %= mod;
      (next[j+1] += next[j]) %= mod;
    }
    // (ans += accumulate(all(dp[i+1]), 0LL)) %= mod;
    (ans += accumulate(all(next), 0LL)) %= mod;
    dp2 = next;
  }
  cout << ans << endk;
  return 0;
}
