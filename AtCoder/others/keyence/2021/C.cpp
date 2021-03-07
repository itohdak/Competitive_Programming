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

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod2;
    (tmp *= tmp) %= mod2;
    N /= 2;
  }
  return ans;
}
ll modinv(ll a, ll m=mod2) {
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
  int h, w, k; cin >> h >> w >> k;
  vector<vector<char>> A(h, vector<char>(w, ' '));
  rep(i, k) {
    int hi, wi; char ci;
    cin >> hi >> wi >> ci;
    hi--; wi--;
    A[hi][wi] = ci;
  }
  vector<vector<ll>> dp(h, vector<ll>(w));
  dp[0][0] = modpow(3, h*w-k);
  ll modinv3 = modinv(3);
  rep(i, h) rep(j, w) {
    if(A[i][j] == ' ') {
      if(i+1 < h) (dp[i+1][j] += dp[i][j] * modinv3 * 2) %= mod2;
      if(j+1 < w) (dp[i][j+1] += dp[i][j] * modinv3 * 2) %= mod2;
    } else if(A[i][j] == 'X') {
      if(i+1 < h) (dp[i+1][j] += dp[i][j]) %= mod2;
      if(j+1 < w) (dp[i][j+1] += dp[i][j]) %= mod2;
    } else if(A[i][j] == 'D') {
      if(i+1 < h) (dp[i+1][j] += dp[i][j]) %= mod2;
    } else {
      if(j+1 < w) (dp[i][j+1] += dp[i][j]) %= mod2;
    }
  }
  // rep(i, h) {
  //   rep(j, w) cout << dp[i][j] << ' ';
  //   cout << endk;
  // }
  cout << dp[h-1][w-1] << endk;
  return 0;
}
