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
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r);
  ans = (ans * finv[r]) % mod;
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<mint> DP(n);
  vector<int> sz(n, 1);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    vector<int> child;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      child.push_back(ne);
      dfs(dfs, ne, cur);
      sz[cur] += sz[ne];
    }
    vector<vector<mint>> dp(child.size()+1, vector<mint>(sz[cur]));
    dp[0][0] = 1;
    int sum = 0;
    rep(i, child.size()) {
      int ne = child[i];
      rep(j, sum+1) {
        REP(k, 1, sz[ne]+1) {
          if(j+k < sz[cur]) {
            dp[i+1][j+k] += dp[i][j] * comb(j+k, k) * comb(sum-j+sz[ne]-k, sz[ne]-k);
          }
        }
      }
      sum += sz[ne];
    }
    assert(sum == sz[cur]-1);
    rep(i, sz[cur]) {
      DP[cur] += dp[child.size()][i];
    }
  };
  dfs(dfs, 0, -1);
  cout << DP[0].val() << endk;
  return 0;
}
