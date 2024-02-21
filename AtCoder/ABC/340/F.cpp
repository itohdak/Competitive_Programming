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
  ll x, y; cin >> x >> y;
  if(x == 0) {
    if(abs(y) == 1) {
      cout << 2 << ' ' << 0 << endk;
    } else if(abs(y) == 2) {
      cout << 1 << ' ' << 0 << endk;
    } else {
      cout << -1 << endk;
    }
  } else if(y == 0) {
    if(abs(x) == 1) {
      cout << 0 << ' ' << 2 << endk;
    } else if(abs(x) == 2) {
      cout << 0 << ' ' << 1 << endk;
    } else {
      cout << -1 << endk;
    }
  } else {
    ll a, b;
    ll g = extGCD(y, -x, a, b);
    if(abs(g) > 2) cout << -1 << endk;
    else cout << a*(2/g) << ' ' << b*(2/g) << endk;
  }
  return 0;
}
