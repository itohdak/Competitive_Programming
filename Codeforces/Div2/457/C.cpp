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
  Eratosthenes(999999);
  int n, m; cin >> n >> m;
  set<tuple<int, int, ll>> E;
  rep(i, n-2) E.insert({i, i+1, 1});
  ll mn = *lower_bound(all(primes), n-1);
  E.insert({n-2, n-1, mn-(n-2)});
  vector<ll> sum(n);
  rep(i, n) sum[i] = (i == n-1 ? mn : i);
  int rem = m-n+1;
  int i = 0;
  while(rem) {
    for(int j=i+2; j<n; j++) {
      if(rem == 0) break;
      E.insert({i, j, sum[j]-sum[i]});
      rem--;
    }
    i++;
  }
  cout << sum[n-1] << ' ' << sum[n-1] << endk;
  for(auto [i, j, w]: E) {
    cout << i+1 << ' ' << j+1 << ' ' << w << endk;
  }
  return 0;
}
