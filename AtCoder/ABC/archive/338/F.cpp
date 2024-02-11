#include <bits/stdc++.h>
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
  int n, m; cin >> n >> m;
  vector<vector<ll>> dist(n, vector<ll>(n, longinf));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    dist[u][v] = w;
  }
  auto warshall_floyd = [&]() {
    rep(i, n) rep(j, n) rep(k, n) {
      if(dist[j][i] == longinf || dist[i][k] == longinf) continue;
      chmin(dist[j][k], dist[j][i]+dist[i][k]);
    }
  };
  warshall_floyd();
  vector<vector<ll>> dp(n, vector<ll>(1<<n, longinf));
  rep(i, n) dp[i][1<<i] = 0;
  rep(b, 1<<n) {
    rep(i, n) {
      rep(j, n) {
        if(dp[i][b] == longinf || dist[i][j] == longinf) continue;
        chmin(dp[j][b|(1<<j)], dp[i][b]+dist[i][j]);
      }
    }
  }
  ll ans = longinf;
  rep(i, n) chmin(ans, dp[i][(1<<n)-1]);
  if(ans == longinf) cout << "No" << endk;
  else cout << ans << endk;
  return 0;
}
