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
  int n, p; cin >> n >> p;
  vector<vector<ll>> X(n+1, vector<ll>(p));
  rep(i, n) rep(j, p) cin >> X[i][j];
  rep(j, p) X[n][j] = X[n-1][j];
  vector<ll> mn(n+1, longinf), mx(n+1, 0);
  rep(i, n+1) {
    rep(j, p) {
      chmin(mn[i], X[i][j]);
      chmax(mx[i], X[i][j]);
    }
  }
  vector<vector<ll>> dp(n+1, vector<ll>(p, longinf));
  rep(j, p) dp[0][j] = X[0][j];
  rep(i, n) {
    rep(j, p) {
      rep(k, p) {
        chmin(dp[i+1][k], dp[i][j]+min({
              abs(X[i][j]-mn[i])+abs(mn[i]-mx[i])+abs(mx[i]-X[i+1][k]),
              abs(X[i][j]-mx[i])+abs(mn[i]-mx[i])+abs(mn[i]-X[i+1][k])
            }));
      }
    }
  }
  cout << *min_element(all(dp[n])) << endk;
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
