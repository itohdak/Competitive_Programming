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
  int n; ll x, y; cin >> n >> x >> y;
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  vector<ll> dp(1<<n, longinf);
  dp[0] = 0;
  rep(i, 1<<n) {
    rep(j, n) {
      if((i>>j)&1) continue;
      int ne = i^(1<<j);
      ll cost = dp[i]+abs(A[j]-B[__builtin_popcount(i)])*x;
      rep(k, j) {
        if(!((i>>k)&1)) cost += y;
      }
      chmin(dp[ne], cost);
    }
  }
  cout << dp[(1<<n)-1] << endk;
  return 0;
}
