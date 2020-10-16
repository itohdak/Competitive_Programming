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

bool arr[2750132];
int minDiv[2750132];
vector<ll> primes;
void Eratosthenes(int N) {
  for(int i=0; i<N; i++) {
    arr[i] = true;
    minDiv[i] = inf;
  }
  for(int i=2; i<N; i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<N; j++) {
        arr[i*(j+2)] = false;
        chmin(minDiv[i*(j+2)], i);
      }
    }
  }
  for(int i=2; i<N; i++) {
    if(arr[i]) {
      primes.push_back(i);
      minDiv[i] = i;
    }
  }
}
bool is_prime(const unsigned n) {
  switch(n) {
  case 0:
  case 1: return false;
  case 2:
  case 3: return true;
  }
  if(n % 2 == 0) return false;
  if(n % 3 == 0) return false;
  if(n % 6 != 1 && n % 6 != 5) return false;
  for(unsigned i=5; i*i<=n; i+=6) {
    if(n % i     == 0) return false;
    if(n % (i+2) == 0) return false;
  }
  return true;
}
void solve() {
  Eratosthenes(2750132);
  unordered_map<ll, int> mp;
  rep(i, primes.size()) mp[primes[i]] = i+1;
  int n; cin >> n;
  vector<ll> B(2*n);
  map<ll, int> cnt;
  rep(i, 2*n) {
    cin >> B[i];
    cnt[B[i]]++;
  }
  vector<ll> A;
  while(cnt.size()) {
    const auto [tmp, m] = *(--cnt.end());
    if(!is_prime(tmp)) {
      ll other = tmp/minDiv[tmp];
      assert(cnt.count(other) && cnt[other] >= m);
      rep(j, m) A.push_back(tmp);
      cnt[other] -= m;
      cnt[tmp] -= m;
      if(cnt[other] == 0) cnt.erase(other);
      if(cnt[tmp] == 0) cnt.erase(tmp);
    } else {
      int other = mp[tmp];
      assert(cnt.count(other) && cnt[other] >= m);
      rep(j, m) A.push_back(other);
      cnt[other] -= m;
      cnt[tmp] -= m;
      if(cnt[other] == 0) cnt.erase(other);
      if(cnt[tmp] == 0) cnt.erase(tmp);
    }
  }
  assert((int)A.size() == n);
  rep(i, n) cout << A[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
