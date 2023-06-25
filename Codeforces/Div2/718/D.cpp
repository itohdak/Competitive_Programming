#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<pair<int, ll>>> G(n*m);
  rep(i, n) {
    rep(j, m-1) {
      ll c; cin >> c;
      int u = i*m+j, v = i*m+(j+1);
      G[u].push_back({v, c});
      G[v].push_back({u, c});
    }
  }
  rep(i, n-1) {
    rep(j, m) {
      ll c; cin >> c;
      int u = i*m+j, v = (i+1)*m+j;
      G[u].push_back({v, c});
      G[v].push_back({u, c});
    }
  }
  if(k%2) {
    rep(i, n) {
      rep(j, m) {
        cout << -1 << ' ';
      }
      cout << endk;
    }
    return;
  }
  vector<vector<ll>> dp(n*m, vector<ll>(k/2+1, longinf));
  rep(i, n*m) dp[i][0] = 0;
  REP(_k, 1, k/2+1) {
    rep(x, n) rep(y, m) {
      int cur = x*m+y;
      for(auto [ne, cost]: G[cur]) {
        chmin(dp[cur][_k], dp[ne][_k-1]+cost);
      }
    }
  }
  rep(x, n) {
    rep(y, m) {
      int cur = x*m+y;
      cout << dp[cur][k/2]*2 << ' ';
    }
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
