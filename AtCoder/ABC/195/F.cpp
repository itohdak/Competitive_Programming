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

bool arr[1000000];
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
  ll a, b; cin >> a >> b;
  Eratosthenes(72);
  int p = primes.size();
  vector<vector<ll>> dp(b-a+2, vector<ll>(1<<p));
  dp[0][0] = 1;
  for(ll i=a; i<=b; i++) {
    ll mask = 0;
    rep(j, p) if(i%primes[j] == 0) mask ^= 1<<j;
    rep(j, 1<<p) {
      dp[i+1-a][j] += dp[i-a][j]; // dont select
      if(j&mask) continue;
      dp[i+1-a][j^mask] += dp[i-a][j]; // select
    }
  }
  cout << accumulate(all(dp.back()), 0LL) << endk;
  return 0;
}
