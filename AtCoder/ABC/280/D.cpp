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

map<ll, int> prime_factorization(ll N) {
  map<ll, int> res;
  if(N == 1 || N == 0) return res;
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
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll k; cin >> k;
  auto ret = prime_factorization(k);
  ll mx = 0;
  for(auto [k, v]: ret) {
    ll n = k;
    int rem = v;
    while(1) {
      ll tmp = n;
      while(tmp % k == 0) {
        rem--;
        tmp /= k;
      }
      if(rem <= 0) break;
      n += k;
    }
    chmax(mx, n);
  }
  cout << mx << endk;
  return 0;
}
