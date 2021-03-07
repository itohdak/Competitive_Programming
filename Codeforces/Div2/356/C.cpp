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
  Eratosthenes(51);
  int cnt = 0;
  int q = 0;
  for(ll p: primes) {
    cout << p << endl;
    string res; cin >> res;
    if(res == "yes") {
      cnt++;
      q = p;
    }
    if(cnt > 1) break;
  }
  if(cnt > 1) cout << "composite" << endl;
  else if(cnt == 0) cout << "prime" << endl;
  else {
    if(q*q > 100) cout << "prime" << endl;
    else {
      cout << q*q << endl;
      string res; cin >> res;
      cout << (res != "yes" ? "prime" : "composite") << endl;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
