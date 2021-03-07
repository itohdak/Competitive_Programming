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

bool arr[71];
vector<ll> primes;
void Eratosthenes(int N) {
  for(int i=0; i<=N; i++) {
    arr[i] = true;
  }
  for(int i=2; i<=N; i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<=N; j++) {
        arr[i*(j+2)] = false;
      }
    }
  }
  for(int i=2; i<=N; i++) {
    if(arr[i]) {
      primes.push_back(i);
    }
  }
}
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
ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Eratosthenes(70);
  int m = primes.size();
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> cnt(71);
  rep(i, n) cnt[A[i]]++;
  vector<int> mask(71);
  rep(i, 71) {
    map<ll, int> res;
    prime_factorization(i, res);
    rep(j, m) {
      ll p = primes[j];
      if(res.count(p) && res[p]%2) {
        mask[i] ^= (1<<j);
      }
    }
  }
  vector<unordered_map<int, ll>> dp(71, unordered_map<int, ll>());
  dp[0][0] = 1;
  rep(i, 71) {
    if(i) {
      rep(j, 1<<m) {
        if(!dp[i-1].count(j)) continue;
        (dp[i][j^mask[i]] += dp[i-1][j] * (cnt[i] == 0 ? 0 : modpow(2, cnt[i]-1))) %= mod;
        (dp[i][j] += dp[i-1][j] * (cnt[i] == 0 ? 1 : modpow(2, cnt[i]-1))) %= mod;
      }
    }
  }
  cout << dp[70][0]-1 << endk;
  return 0;
}
