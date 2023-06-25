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

void prime_factorization(ll N, map<ll, int>& res) {
  if(N == 1 || N == 0) return;
  ll n = N;
  ll i = 2;
  while(n >= i * i) {
    while(n % i == 0) {
      if(res.count(i)) res[i]++;
      else res[i] = 1;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
  }
  if(n != 1) res[n]++;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m, k; cin >> n >> m >> k;
  ll g = __gcd(n*m, k);
  if(k / g > 2) {
    cout << "NO" << endk;
    return 0;
  }
  k /= g;
  if(k == 1) {
    if(g == 1) {
      cout << "NO" << endk;
    } else {
      map<ll, int> res;
      prime_factorization(g, res);
      ll a = n, b = m, c = 2;
      for(auto ele: res) {
        rep(i, ele.second) {
          if(c % ele.first == 0) c /= ele.first;
          else if(a % ele.first == 0) a /= ele.first;
          else if(b % ele.first == 0) b /= ele.first;
          else assert(false);
        }
      }
      if(a * c <= n) {
        cout << "YES" << endk;
        cout << 0 << ' ' << 0 << endk;
        cout << a*c << ' ' << 0 << endk;
        cout << 0 << ' ' << b << endk;
      } else if(b * c <= m) {
        cout << "YES" << endk;
        cout << 0 << ' ' << 0 << endk;
        cout << a << ' ' << 0 << endk;
        cout << 0 << ' ' << b*c << endk;
      }
    }
  } else {
    map<ll, int> res;
    prime_factorization(g, res);
    ll a = n, b = m;
    for(auto ele: res) {
      rep(i, ele.second) {
        if(a % ele.first == 0) a /= ele.first;
        else if(b % ele.first == 0) b /= ele.first;
        else assert(false);
      }
    }
    cout << "YES" << endk;
    cout << 0 << ' ' << 0 << endk;
    cout << a << ' ' << 0 << endk;
    cout << 0 << ' ' << b << endk;
  }
  return 0;
}
