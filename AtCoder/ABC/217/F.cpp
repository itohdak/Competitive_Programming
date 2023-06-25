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

#define MAX_N 200010
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
  int n, m; cin >> n >> m;
  vector<int> A(m), B(m);
  vector<set<int>> vst(2*n);
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    vst[A[i]].insert(B[i]);
  }
  vector<vector<ll>> dp(2*n+1, vector<ll>(2*n+1, 0));
  rep(i, 2*n+1) dp[i][i] = 1;
  for(int len=2; len<=2*n; len+=2) {
    rep(l, 2*n) {
      int r = l+len;
      if(r > 2*n) break;
      for(int r2=l+2; r2<=r; r2+=2) {
        if(vst[l].count(r2-1)) (dp[l][r] += dp[l+1][r2-1] * dp[r2][r] % mod2 * comb((r-l)/2, (r-r2)/2) % mod2) %= mod2;
      }
    }
  }
  cout << dp[0][2*n] << endk;
  return 0;
}
