#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

void solve() {
  int r, g, b; cin >> r >> g >> b;
  vector<ll> R(r), G(g), B(b);
  rep(i, r) cin >> R[i];
  rep(i, g) cin >> G[i];
  rep(i, b) cin >> B[i];
  sort(all(R), greater<ll>());
  sort(all(G), greater<ll>());
  sort(all(B), greater<ll>());
  vector<vector<vector<ll>>> dp(r+1, vector<vector<ll>>(g+1, vector<ll>(b+1)));
  rep(i, r+1) rep(j, g+1) rep(k, b+1) {
    if(i!=r && j!=g) dp[i+1][j+1][k] = max(dp[i][j][k]+R[i]*G[j], dp[i+1][j+1][k]);
    if(i!=r && k!=b) dp[i+1][j][k+1] = max(dp[i][j][k]+R[i]*B[k], dp[i+1][j][k+1]);
    if(j!=g && k!=b) dp[i][j+1][k+1] = max(dp[i][j][k]+G[j]*B[k], dp[i][j+1][k+1]);
  }
  ll ans = 0;
  rep(i, r+1) rep(j, g+1) rep(k, b+1) ans = max(dp[i][j][k], ans);
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
