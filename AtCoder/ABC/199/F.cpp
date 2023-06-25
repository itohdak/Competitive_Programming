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
vector<vector<ll>> matmul(vector<vector<ll>>& A,
                           vector<vector<ll>>& B) {
  int n = A.size();
  int m = B.size();
  int l = B[0].size();
  vector<vector<ll>> ret(n, vector<ll>(l));
  rep(i, n) rep(k, l) rep(j, m) (ret[i][k] += A[i][j] * B[j][k]) %= mod;
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; ll k; cin >> n >> m >> k;
  vector<vector<ll>> A(n, vector<ll>(1));
  rep(i, n) cin >> A[i][0];
  vector<vector<ll>> M(n, vector<ll>(n));
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    M[u][v] = M[v][u] = 1;
  }
  rep(i, n) {
    ll sum = accumulate(all(M[i]), 0LL);
    M[i][i] = 2*m - sum;
  }
  ll modinv2m = modinv(2*m);
  rep(i, n) rep(j, n) {
    (M[i][j] *= modinv2m) %= mod;
  }
  vector<vector<vector<ll>>> MM(60, vector<vector<ll>>(n, vector<ll>(n)));
  copy(all(M), begin(MM[0]));
  for(int i=1; i<60; i++) {
    MM[i] = matmul(MM[i-1], MM[i-1]);
  }
  vector<vector<ll>> K(n, vector<ll>(n));
  rep(i, n) K[i][i] = 1;
  rep(i, 60) {
    if((k>>i)&1) {
      K = matmul(K, MM[i]);
    }
  }
  auto ans = matmul(K, A);
  rep(i, n) cout << ans[i][0] << endk;
  return 0;
}
