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


ld calc(ll x1, ll y1, ll x2, ll y2, ll sp) {
  return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/(1<<sp);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> X(n+m), Y(n+m);
  rep(i, n) cin >> X[i] >> Y[i];
  rep(i, m) cin >> X[n+i] >> Y[n+i];
  vector<vector<vector<ld>>> dp(m+1, vector<vector<ld>>(n+m, vector<ld>(1<<(n+m), longinf)));
  rep(i, n+m) {
    dp[i>=n][i][1<<i] = calc(0, 0, X[i], Y[i], 0);
  }
  rep(i, 1<<(n+m)) {
    if(i == 0) continue;
    rep(j, n+m) { // curr
      if(!((i>>j)&1)) continue;
      rep(k, n+m) { // next
        if((i>>k)&1) continue;
        rep(l, m+1) {
          if(l+(k>=n) > m) continue;
          chmin(dp[l+(k>=n)][k][i^(1<<k)], dp[l][j][i]+calc(X[j], Y[j], X[k], Y[k], l));
        }
      }
    }
  }
  ld ans = longinf;
  rep(i, 1<<(n+m)) {
    if((i&((1<<n)-1)) != (1<<n)-1) continue;
    rep(j, m+1) {
      rep(k, n+m) {
        chmin(ans, dp[j][k][i]+calc(X[k], Y[k], 0, 0, j));
      }
    }
  }
  cout << fixed << setprecision(10) << ans << endk;
  return 0;
}
