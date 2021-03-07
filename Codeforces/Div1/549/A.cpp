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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, k; cin >> n >> k;
  ll m = 1LL * n * k;
  ll a, b; cin >> a >> b;
  ll mn = longinf, mx = 0;
  for(ll first: {a, -a}) {
    first = (first + m) % m;
    rep(i, n) {
      for(ll second: {k*i-b, k*i+b}) {
        second = (second + m) % m;
        ll l = (second - first + m) % m;
        if(l == 0) l += m;
        // cout << l << endk;
        ll gcd = __gcd(m, l);
        ll tmp = m/gcd;
        chmin(mn, tmp);
        chmax(mx, tmp);
      }
    }
  }
  cout << mn << ' ' << mx << endk;
  return 0;
}
