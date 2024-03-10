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
  vector<vector<ll>> P(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> P[i][j];
  vector<vector<ll>> R(n, vector<ll>(n, longinf)), D(n, vector<ll>(n, longinf));
  rep(i, n) rep(j, n-1) cin >> R[i][j];
  rep(i, n-1) rep(j, n) cin >> D[i][j];
  vector<vector<ll>> dist(n*n, vector<ll>(n*n, longinf));
  rep(i, n) rep(j, n) {
    int rt = i*n+j;
    dist[rt][rt] = 0;
    REP(k, i, n) {
      REP(l, j, n-1) {
        chmin(dist[rt][k*n+(l+1)], dist[rt][k*n+l]+R[k][l]);
      }
      if(i+1 < n) {
        REP(l, j, n) {
          chmin(dist[rt][(k+1)*n+l], dist[rt][k*n+l]+D[k][l]);
        }
      }
    }
  }
  vector<ll> dp(n*n, longinf);
  vector<ll> rem(n*n, 0);
  dp[0] = 0;
  rem[0] = 0;
  rep(i, n*n) {
    ll p = P[i/n][i%n];
    REP(x, i/n, n) {
      REP(y, i%n, n) {
        int j = x*n+y;
        ll cost = dp[i]+max(0LL, (dist[i][j]-rem[i]+p-1)/p);
        if(dp[j] > cost) {
          dp[j] = cost;
          rem[j] = (p-(dist[i][j]-rem[i])%p)%p;
        } else if(dp[j] == cost) {
          chmax(rem[j], (p-(dist[i][j]-rem[i])%p)%p);
        }
      }
    }
  }
  cout << dp[n*n-1]+(n-1)*2 << endk;
  return 0;
}
