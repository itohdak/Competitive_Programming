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
  ll n, s; cin >> n >> s;
  if(n == s) {
    cout << n+1 << endk;
    return 0;
  }
  for(ll b=2; b*b<=n; b++) {
    ll sum = 0;
    ll _n = n;
    while(_n) {
      sum += _n % b;
      _n /= b;
    }
    if(sum == s) {
      cout << b << endk;
      return 0;
    }
  }
  ll ans = longinf;
  for(ll p=1; p*p<n; p++) {
    ll q = s - p;
    if((n - q) % p) continue;
    ll b = (n - q) / p;
    if(q < 0 || q >= b) continue;
    chmin(ans, b);
  }
  cout << (ans == longinf ? -1 : ans) << endk;
  return 0;
}
