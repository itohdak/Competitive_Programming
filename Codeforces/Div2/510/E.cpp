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
// const ll mod = 1e9+7;
const ll mod = 998244353;
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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<ll>> A(n, vector<ll>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  int r, c; cin >> r >> c;
  r--; c--;
  vector<int> id(n*m);
  iota(all(id), 0);
  auto val = [&](int id) {
    return A[id/m][id%m];
  };
  sort(all(id), [&](int i, int j) {
    return val(i) > val(j);
  });
  vector<ll> dp(n*m+1);
  vector<ll> prob(n*m+1);
  vector<ll> expX(n*m+1), expY(n*m+1);
  ll expx = 0, expx2 = 0, expy = 0, expy2 = 0;
  prob[find(all(id), r*m+c)-begin(id)] = 1;
  int i = 0;
  while(i < n*m) {
    int ib = i;
    while(i < n*m && val(id[i]) == val(id[ib])) i++;
    int nless = n*m-i;
    cout << i << endk;
    cout << nless << endk;
    ll p = (nless == 0 ? 1 : modinv(nless));
    for(int j=ib; j<i-1; j++) prob[j+1] = prob[j], expX[j+1] = expX[j], expY[j+1] = expY[j];
    for(int j=ib; j<i; j++) {
      ll r = id[j]/m, r2 = r*r;
      ll c = id[j]%m, c2 = c*c;
      (expX[j] += expx2 - 2 * expx * r + prob[j] * r2) %= mod;
      (expY[j] += expy2 - 2 * expy * c + prob[j] * c2) %= mod;
      (expx  += prob[j] * p % mod * r  % mod) %= mod;
      (expx2 += prob[j] * p % mod * r2 % mod) %= mod;
      (expy  += prob[j] * p % mod * c  % mod) %= mod;
      (expy2 += prob[j] * p % mod * c2 % mod) %= mod;
      prob[i] += prob[j] * p;
      expX[i] += expX[j] * p;
      expY[i] += expY[j] * p;
    }
  }
  cout << id << endk;
  cout << prob << endk;
  cout << expX << endk << expY << endk;
  cout << (expX[n*m] + expY[n*m]) % mod << endk;
  return 0;
}
