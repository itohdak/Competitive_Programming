#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

using mint = modint998244353;

#define MAX_N 2000005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod2 - inv[mod2%i] * (mod2/i) % mod2;
    fac[i] = fac[i-1] * (ll)i % mod2;
    finv[i] = finv[i-1] * inv[i] % mod2;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod2;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r);
  ans = (ans * finv[r]) % mod2;
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n; cin >> n;
  vector<vector<mint>> dp(n+1, vector<mint>(n+1));
  dp[1][1] = 1;
  mint div2 = (mint)1/2;
  vector<mint> pw(n+1);
  pw[0] = 1;
  rep(i, n) pw[i+1] = pw[i] * div2;
  for(int i=2; i<=n; i++) {
    mint a = 0;
    mint b = 0;
    vector<mint> memo(i+1);
    cout << "======" << endk;
    for(int j=1; j<=i; j++) {
      for(int k=0; k<=j-1; k++) {
        mint tmp = pw[j-1] * comb(j-1, k);
        if(k == 0) {
          a += tmp;
        } else {
          mint tmp2 = tmp * dp[j-k][1];
          b += tmp2;
          memo[j] += tmp2;
        }
      }
    }
    // a * p + b == 1
    cout << a.val() << ' ' << b.val() << endk;
    cout << ((mint)7/4).val() << ' ' << ((mint)7/12).val() << endk;
    dp[i][1] = ((mint)1-b)/a;
    for(int j=2; j<=i; j++) {
      dp[i][j] = pw[j-1] * dp[i][1] + memo[j];
    }
  }
  for(int i=1; i<=n; i++) cout << dp[n][i].val() << ' ';
  cout << endk;
  return 0;
}
