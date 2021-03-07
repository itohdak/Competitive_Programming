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
  int n; ll k; cin >> n >> k;
  vector<ll> A(n), B(n), C(n);
  rep(i, n) cin >> A[i] >> B[i] >> C[i];
  B[n-1] = k;

  auto coef = [&](ll n, ll c) {
    vector<vector<ll>> M(c+1, vector<ll>(c+1));
    rep(i, c+1) rep(di, 3) {
      if(i-1+di >= 0 && i-1+di<c+1) {
        M[i][i-1+di] = 1LL;
      }
    }
    vector<vector<vector<ll>>> MM(60, vector<vector<ll>>(c+1, vector<ll>(c+1)));
    copy(all(M), begin(MM[0]));
    for(int i=1; i<60; i++) {
      MM[i] = matmul(MM[i-1], MM[i-1]);
      rep(j, c+1) rep(k, c+1) (MM[i][j][k] += mod) %= mod;
    }
    vector<vector<ll>> K(c+1, vector<ll>(c+1));
    rep(i, c+1) K[i][i] = 1;
    rep(i, 60) if(n>>i&1) {
      K = matmul(K, MM[i]);
      rep(j, c+1) rep(k, c+1) (K[j][k] += mod) %= mod;
    }
    return K;
  };

  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(16, vector<ll>(1)));
  dp[0][0][0] = 1;
  rep(i, n) {
    auto M = coef(B[i]-A[i], C[i]);
    vector<vector<ll>> a(C[i]+1, vector<ll>(1));
    rep(j, C[i]+1) a[j][0] = dp[i][j][0];
    auto ret = matmul(M, a);
    rep(j, C[i]+1) dp[i+1][j][0] = ret[j][0];
  }
  cout << dp[n][0][0] << endk;
  return 0;
}
