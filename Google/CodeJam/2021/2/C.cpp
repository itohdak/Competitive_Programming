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

void solve() {
  int n; cin >> n;
  vector<int> V(n); rep(i, n) cin >> V[i];
  if(n > 13) {
    cout << -1 << endk;
    return;
  }
  vector<ll> dp(1<<n);
  dp[0] = 1;
  rep(i, 1<<n) {
    int pop = __builtin_popcount(i);
    int tmp = V[pop];
    int k = n-1;
    while(k >= 0 && tmp > 1) {
      if((i>>k)&1) tmp--;
      k--;
    }
    if(tmp > 1) continue;
    while(k >= 0) {
      if((i>>k)&1) break;
      (dp[i^(1<<k)] += dp[i]) %= mod;
      cout << i << " to " << (i^(1<<k)) << endk;
      k--;
    }
  }
  cout << dp << endk;
  cout << dp[(1<<n)-1] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}