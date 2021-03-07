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
  for(int i=0; i<N; i++) {
    arr[i] = true;
  }
  for(int i=2; i<N; i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<N; j++) {
        arr[i*(j+2)] = false;
      }
    }
  }
  for(int i=2; i<N; i++) {
    if(arr[i]) {
      primes.push_back(i);
    }
  }
}
void solve() {
  int d; cin >> d;
  // 1 d+1 2*d+1 (d+1)(2*d+1)
  ll p1 = *lower_bound(all(primes), 1+d);
  ll p2 = *lower_bound(all(primes), p1+d);
  cout << p1*p2 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Eratosthenes(1000000);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
