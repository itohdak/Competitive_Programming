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
  int t; cin >> t;
  while(t--) {
    ll n, s, k;
    cin >> n >> s >> k;
    k %= n;
    ll gcd = __gcd(n, k);
    if(s % gcd != 0) {
      cout << -1 << endk;
      continue;
    }
    n /= gcd, s /= gcd, k /= gcd;
    ll x, y;
    extGCD(n, k, x, y);
    // n * x + k * y == 1
    if(y > 0) {
      assert(x <= 0);
      ll m = abs(x)/k+1;
      // ll m = (y+n-1)/n;
      x += m*k;
      y -= m*n;
      assert(x > 0);
    }
    y = -y;
    cout << (y % n) * (s % n) % n << endk;
  }
  return 0;
}
