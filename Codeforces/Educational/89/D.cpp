#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

bool arr[10000010];
ll prime[10000010];
vector<ll> primes;
void Eratosthenes(int N) {
  for(int i=0; i<N; i++) {
    arr[i] = true;
    prime[i] = 1;
  }
  for(int i=2; i<sqrt(N); i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<N; j++) {
        arr[i*(j+2)] = false;
        prime[i*(j+2)] = i;
      }
    }
  }

  for(int i=2; i<N; i++) {
    if(arr[i]) {
      primes.push_back(i);
      prime[i] = i;
    }
  }
}

int main() {
  Eratosthenes(10000005);
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> A(n);
  vector<pair<ll, ll>> ans(n);
  rep(i, n) {
    cin >> A[i];
    if(prime[A[i]] == 1 || prime[A[i]] == A[i]) {
      ans[i].first = ans[i].second = -1;
    } else {
      ll res = A[i];
      ll p = prime[A[i]];
      while(res % p == 0) res /= p;
      if(res == 1) {
        ans[i].first = ans[i].second = -1;
      } else {
        ans[i].first = res;
        ans[i].second = A[i]/res;
      }
    }
  }
  rep(i, n) cout << ans[i].first << ' ';
  cout << endl;
  rep(i, n) cout << ans[i].second << ' ';
  cout << endl;
  return 0;
}
