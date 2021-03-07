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

vector<vector<ll>> matmul(vector<vector<ll>>& A,
                           vector<vector<ll>>& B) {
  int n = A.size();
  int m = B.size();
  int l = B[0].size();
  vector<vector<ll>> ret(n, vector<ll>(l));
  rep(i, n) rep(k, l) rep(j, m) (ret[i][k] += A[i][j] * B[j][k]) %= (mod-1);
  return ret;
}

ll modpow(ll a, ll N, ll mod=mod) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
/*
 * x^k ≡ y (mod m) なるkを求める
 */
ll BabyStepGiantStep(ll x, ll y, ll m) {
  ll sq = ceil(sqrt(m));

  // Baby-step
  ll pw = 1;
  map<ll, ll> mp;
  mp[pw] = 0;
  rep(i, sq) {
    (pw *= x) %= m;
    mp[pw] = i+1;
  }
  if(mp.count(y)) return mp[y];

  // Giant-step
  ll r = modpow(pw, m-2, m); // x^(-sq)
  REP(i, 1, sq+1) {
    (y *= r) %= m;
    if(mp.count(y)) return mp[y] + i*sq;
  }

  return -1;
}

/*
  拡張GCD
  不定方程式 a * x + b * y == gcd(a, b)
  の解を (x, y) に格納する
*/
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b * x;
  return d;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int k; cin >> k;
  vector<ll> B(k); rep(i, k) cin >> B[i];
  ll n, m; cin >> n >> m;
  n--;
  vector<vector<ll>> M(k, vector<ll>(k));
  rep(j, k-1) M[j+1][j] = 1;
  rep(i, k) M[i][k-1] = B[k-1-i];
  vector<vector<vector<ll>>> MM(35, vector<vector<ll>>(k, vector<ll>(k)));
  copy(all(M), begin(MM[0]));
  for(int i=1; i<35; i++) {
    MM[i] = matmul(MM[i-1], MM[i-1]);
  }
  vector<vector<ll>> K(k, vector<ll>(k));
  rep(i, k) K[i][i] = 1;
  rep(i, 35) {
    if((n>>i)&1) {
      K = matmul(K, MM[i]);
    }
  }
  ll p = K[k-1][0];
  // x^p ≡ m (mod mod-1)
  // cout << "x^" << p << " ≡ " << m << " (mod " << mod-1 << ")" << endk;
  ll km = BabyStepGiantStep(3, m, mod);
  if(km == -1) {
    cout << -1 << endk;
    return 0;
  }
  // cout << 3 << "^" << km << " ≡ " << m << " (mod " << mod << ")" << endk;
  assert(modpow(3, km, mod) == m);
  // kx * p ≡ km (mod mod-1)
  // kx * p == (mod-1) * q + km
  ll x, y;
  extGCD(p, mod-1, x, y);
  ll g = __gcd(p, mod-1);
  // cout << p << " * " << x << " + " << mod-1 << " * " << y << " == " << g << endk;
  if(x < 0) {
    ll d = (mod-1) / g;
    x += (abs(x)+d-1) / d * d;
  }
  // p * x + (mod-1) * y == g
  // p * (x*km/g) + (mod-1) * (y*km/g) == km
  // p * (x*km/g) ≡ km (mod mod-1)
  if(km%g) {
    cout << -1 << endk;
    return 0;
  }
  ll kx = x*(km/g)%(mod-1);
  cout << modpow(3, kx) << endk;
  return 0;
}
