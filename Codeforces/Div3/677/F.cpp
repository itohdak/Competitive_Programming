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
  vector<vector<int>> A(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  vector<vector<ll>> B(n, vector<ll>(k));
  rep(i, n) {
    vector<vector<vector<ll>>> dp(m+1, vector<vector<ll>>(k, vector<ll>(m/2+1, -longinf)));
    dp[0][0][0] = 0;
    rep(j, m) {
      rep(v, k) { // reminder of sum
        rep(u, m/2+1) { // how many has been selected
          chmax(dp[j+1][v][u], dp[j][v][u]); // not select
          if(u < m/2) {
            if((v+A[i][j])%k < 0) continue;
            chmax(dp[j+1][(v+A[i][j])%k][u+1], dp[j][v][u]+A[i][j]);
          }
        }
      }
    }
    rep(j, k) B[i][j] = *max_element(all(dp[m][j]));
  }
  vector<vector<ll>> dpAll(n+1, vector<ll>(k, -longinf));
  dpAll[0][0] = 0;
  rep(i, n) {
    rep(j, k) {
      chmax(dpAll[i+1][j], dpAll[i][j]);
      rep(v, k) {
        if((j+B[i][v])%k < 0) continue;
        chmax(dpAll[i+1][(j+B[i][v])%k], dpAll[i][j]+B[i][v]);
      }
    }
  }
  cout << dpAll[n][0] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
