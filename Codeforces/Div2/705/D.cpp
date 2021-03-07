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

void solve() {
  constexpr ll MAX = 1000000;
  auto spf = smallest_prime_factors(MAX);
  Eratosthenes(200000);
  int n, q;
  cin >> n >> q;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int np = primes.size();
  vector<multiset<int>> cnt(np);
  vector<map<int, int>> cntp(n);
  rep(i, n) {
    auto ret = factorization(A[i], spf);
    map<int, int> cnt2;
    for(ll p: ret) cnt2[p]++;
    for(auto ele: cnt2) {
      int j = lower_bound(all(primes), ele.first) - begin(primes);
      cnt[j].insert(ele.second);
      cntp[i][j] += ele.second;
    }
  }
  ll g = A[0];
  rep(i, n) g = __gcd(g, A[i]);
  rep(_, q) {
    int i; ll x; cin >> i >> x;
    i--;
    auto ret = factorization(x, spf);
    map<int, int> cnt2;
    for(ll p: ret) cnt2[p]++;
    for(auto ele: cnt2) {
      int j = lower_bound(all(primes), ele.first) - begin(primes);
      if(!cntp[i].count(j)) {
        cntp[i][j] += ele.second;
        cnt[j].insert(ele.second);
        if(cnt[j].size() == n) (g *= modpow(ele.first, *cnt[j].begin())) %= mod;
      } else {
        int tmp = *cnt[j].begin();
        cnt[j].erase(cnt[j].find(cntp[i][j]));
        cntp[i][j] += ele.second;
        cnt[j].insert(cntp[i][j]);
        if(cnt[j].size() == n) (g *= modpow(ele.first, *cnt[j].begin()-tmp)) %= mod;
      }
    }
    cout << g << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
