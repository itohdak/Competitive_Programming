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

template<typename T>
vector<T> smallest_prime_factors(T n) {
  vector<T> spf(n + 1);
  for(int i=0; i<=n; i++) spf[i] = i;
  for(T i=2; i*i<=n; i++) {
    // 素数だったら
    if(spf[i] == i) {
      for(T j=i*i; j<=n; j+=i) {
        // iを持つ整数かつまだ素数が決まっていないなら
        if(spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
  return spf;
}

template<typename T>
vector<T> factorization(T x, vector<T>& spf) {
  vector<T> ret;
  while(x != 1) {
    ret.push_back(spf[x]);
    x /= spf[x];
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll t; int l, r; cin >> t >> l >> r;
  constexpr ll MAX = 5000000;
  auto spf = smallest_prime_factors(MAX);
  vector<ll> f(MAX+1);
  // for(ll i=2; i<=MAX; i++) {
  //   auto ret = factorization(i, spf);
  //   ll tmp = i;
  //   for(ll d: ret) {
  //     (f[i] += (d-1)*tmp/2) %= mod;
  //     tmp /= d;
  //   }
  // }
  for(ll i=2; i<=MAX; i++) {
    if(spf[i] == i) {
      (f[i] = (spf[i]-1)*i/2) %= mod;
    } else {
      (f[i] = (spf[i]-1)*i/2 + f[i/spf[i]]) %= mod;
    }
  }
  ll ans = 0;
  ll pw = 1;
  for(int i=l; i<=r; i++) {
    (ans += pw * f[i]) %= mod;
    (pw *= t) %= mod;
  }
  cout << ans << endk;
  return 0;
}
