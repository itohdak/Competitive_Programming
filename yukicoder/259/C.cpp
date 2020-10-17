#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<vector<ll>> A(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  vector<vector<vector<ll>>> sum(4, vector<vector<ll>>(h+2, vector<ll>(w+2, 1)));
  //
  rep(i, h) rep(j, w) sum[0][i+1][j+1] = sum[0][i+1][j] * A[i][j] % mod;
  rep(j, w) rep(i, h) (sum[0][i+1][j+1] *= sum[0][i][j+1]) %= mod;
  //
  rep(i, h) rrep(j, w) sum[1][i+1][j+1] = sum[1][i+1][j+2] * A[i][j] % mod;
  rep(j, w) rep(i, h) (sum[1][i+1][j+1] *= sum[1][i][j+1]) %= mod;
  //
  rep(i, h) rep(j, w) sum[2][i+1][j+1] = sum[2][i+1][j] * A[i][j] % mod;
  rep(j, w) rrep(i, h) (sum[2][i+1][j+1] *= sum[2][i+2][j+1]) %= mod;
  //
  rep(i, h) rrep(j, w) sum[3][i+1][j+1] = sum[3][i+1][j+2] * A[i][j] % mod;
  rep(j, w) rrep(i, h) (sum[3][i+1][j+1] *= sum[3][i+2][j+1]) %= mod;
  //
  // rep(i, 4) cout << sum[i] << endl;
  int q; cin >> q;
  while(q--) {
    int r, c; cin >> r >> c;
    r--; c--;
    cout << sum[0][r][c] * sum[1][r][c+2] % mod * sum[2][r+2][c] % mod * sum[3][r+2][c+2] % mod << "\n";
  }
  return 0;
}
