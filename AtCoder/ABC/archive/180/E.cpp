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

vector<vector<ll>> dist;

void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> X(n), Y(n), Z(n);
  rep(i, n) cin >> X[i] >> Y[i] >> Z[i];
  dist.assign(n, vector<ll>(n, longinf));
  rep(i, n) {
    rep(j, n) {
      dist[i][j] = abs(X[i]-X[j]) + abs(Y[i]-Y[j]) + max(0LL, Z[j]-Z[i]);
    }
  }
  warshall_floyd(n);
  vector<vector<ll>> dp(1<<n, vector<ll>(n, longinf));
  dp[0][0] = 0;
  rep(i, 1<<n) {
    rep(j, n) {
      rep(k, n) {
        if((i>>k)&1) continue;
        chmin(dp[i|(1<<k)][k], dp[i][j]+dist[j][k]);
      }
    }
  }
  ll ans = longinf;
  rep(j, n) {
    chmin(ans, dp[(1<<n)-1][j]+dist[j][0]);
  }
  cout << ans << endk;
  return 0;
}
