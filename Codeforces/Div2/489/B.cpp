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
  ll l, r, x, y; cin >> l >> r >> x >> y;
  if(y % x != 0) {
    cout << 0 << endk;
    return 0;
  }
  ll z = y/x;
  map<ll, int> res;
  prime_factorization(z, res);
  vector<ll> val;
  for(auto ele: res) {
    val.push_back(1);
    rep(i, ele.second) val.back() *= ele.first;
  }
  int n = val.size();
  ll ans = 0;
  rep(i, 1<<n) {
    ll mul = 1;
    rep(j, n) if((i>>j)&1) mul *= val[j];
    ll res = z / mul;
    if(l <= x*res && x*res <= r &&
       l <= x*mul && x*mul <= r) ans++;
  }
  cout << ans << endk;
  return 0;
}
