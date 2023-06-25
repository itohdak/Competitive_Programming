#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

bool arr[10000001];
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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Eratosthenes(10000000);
  int sz = primes.size();
  vector<int> dp(sz, inf);
  dp[0] = 0, dp[1] = 1;
  REP(i, 1, sz-1) {
    dp[i+1] = dp[i] + primes[i+1]-primes[i]-1;
  }
  // cout << primes[sz-1] << endk;
  // rep(i, 10) cout << primes[i] << ' '; cout << endk;
  // rep(i, 10) cout << dp[i] << ' '; cout << endk;
  int T;
  cin >> T;
  auto isPrime = [&](int x) {
    auto itr = lower_bound(all(primes), x);
    if(itr == primes.end()) return false;
    return *itr == x;
  };
  auto solve = [&]() {
    int x, y; cin >> x >> y;
    auto litr = lower_bound(all(primes), x);
    auto lpos = litr - begin(primes);
    auto ritr = --upper_bound(all(primes), y);
    auto rpos = ritr - begin(primes);
    if(litr > ritr) {
      cout << y-x << endk;
    } else {
      int ans = dp[rpos]-dp[lpos];
      // cout << *litr << ' ' << *ritr << ' ' << ans << endk;
      if(!isPrime(x)) {
        ans += max(1, int(*litr-x-1));
      }
      if(!isPrime(y)) {
        ans += int(y-*ritr);
      }
      if(x == 1 && y >= 3) ans--;
      cout << ans << endk;
    }
  };
  while(T--) solve();
  return 0;
}
