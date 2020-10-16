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
void find_divisor(ll N, vector<ll>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
void solve() {
  ll n; cin >> n;
  map<ll, int> primes; // 素因数分解
  prime_factorization(n, primes);
  // vector<ll> div; // 約数
  // find_divisor(n, div);
  int nPrimes = primes.size(); // 素因数の個数
  ll m = 1; // 約数の個数
  vector<ll> P; // 素因数
  for(auto ele: primes) {
    m *= ele.second+1;
    P.push_back(ele.first);
  }
  vector<ll> ans(m-1);
  vector<int> cnt; // i番目の素因数を約数にもつnの約数の個数
  for(auto ele: primes) {
    cnt.push_back(m/(ele.second+1)*ele.second);
    m /= (ele.second+1);
  }
  map<ll, set<ll>> P2; // i番目の素因数を約数にもつnの約数
  // for(auto d: div) {
  //   if(d == 1) continue;
  //   map<ll, int> p;
  //   prime_factorization(d, p);
  //   P2[p.begin()->first].insert(d);
  // }
  auto dfs = [&](auto dfs, int cur, ll mul, ll mn=longinf) {
    if(cur == nPrimes) {
      if(mn != longinf) {
        P2[mn].insert(mul);
      }
      return;
    }
    rep(i, primes[P[cur]]+1) {
      dfs(dfs, cur+1, mul, (i==0 ? mn : min(P[cur], mn)));
      mul *= P[cur];
    }
  };
  dfs(dfs, 0, 1LL);
  if(primes.size() == 1) {
    // for(auto d: div) if(d != 1) cout << d << ' ';
    // cout << endk;
    for(auto d: P2[P[0]]) cout << d << ' ';
    cout << endk;
    cout << 0 << endk;
  } else if(primes.size() == 2) {
    bool allOne = true;
    for(auto ele: primes) if(ele.second > 1) allOne = false;
    if(allOne) {
      ans[0] = P[0] * P[1];
      P2[P[0]].erase(ans[0]);
      int j = 1;
      rep(i, nPrimes) {
        while(!P2[P[i]].empty()) {
          ans[j] = *P2[P[i]].begin();
          P2[P[i]].erase(ans[j]);
          j++;
        }
      }
      for(auto a: ans) cout << a << ' ';
      cout << endk;
      cout << 1 << endk;
    } else {
      ans[0] = P[0] * P[1];
      P2[P[0]].erase(ans[0]);
      ans[P2[P[0]].size()] = P[0] * P[1] * (primes[P[0]]>1 ? P[0] : P[1]);
      P2[P[0]].erase(ans[P2[P[0]].size()]);
      int j = 0;
      rep(i, nPrimes) {
        j++;
        while(!P2[P[i]].empty()) {
          ans[j] = *P2[P[i]].begin();
          P2[P[i]].erase(ans[j]);
          j++;
        }
      }
      for(auto a: ans) cout << a << ' ';
      cout << endk;
      cout << 0 << endk;
    }
  } else {
    int j = 0;
    vector<int> pos(nPrimes);
    rep(i, nPrimes) {
      ans[j] = P[i] * P[(i-1+nPrimes)%nPrimes];
      P2[P[i]].erase(ans[j]);
      P2[P[(i-1+nPrimes)%nPrimes]].erase(ans[j]);
      j += P2[P[i]].size();
    }
    j = 0;
    rep(i, nPrimes) {
      j++;
      while(!P2[P[i]].empty()) {
        ans[j] = *P2[P[i]].begin();
        P2[P[i]].erase(ans[j]);
        j++;
      }
    }
    for(auto a: ans) cout << a << ' ';
    cout << endk;
    cout << 0 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
