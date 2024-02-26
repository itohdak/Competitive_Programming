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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  int zero = 0;
  map<int, int> cnt;
  rep(i, n) {
    if(A[i] == 0) zero++;
    else {
      auto mp = prime_factorization(A[i]);
      int b = 1;
      for(auto [k, v]: mp) {
        if(v&1) b *= k;
      }
      cnt[b]++;
    }
  }
  ll ans = 0;
  ans += 1LL * zero * (n-zero) + 1LL * zero * (zero-1) / 2;
  for(auto [k, v]: cnt) {
    ans += 1LL * v * (v-1) / 2;
  }
  cout << ans << endk;
  return 0;
}
