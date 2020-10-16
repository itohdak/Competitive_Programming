#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M));
  rep(i, N) rep(j, M) cin >> A[i][j];
  ll ans = longinf;
  rep(k, N) rep(l, M) {
    ll base = A[k][l]-k-l;
    vector<vector<ll>> dp(N, vector<ll>(M, longinf));
    dp[0][0] = A[0][0]-base;
    rep(i, N) rep(j, M) {
      if(A[i][j] < base+i+j) continue;
      if(i+1<N) dp[i+1][j] = min(dp[i][j]+(A[i+1][j]-(base+i+1+j)), dp[i+1][j]);
      if(j+1<M) dp[i][j+1] = min(dp[i][j]+(A[i][j+1]-(base+i+j+1)), dp[i][j+1]);
    }
    // cout << base << ' ' << dp[N-1][M-1] << endl;
    if(A[N-1][M-1] >= base+N-1+M-1) ans = min(dp[N-1][M-1], ans);
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
