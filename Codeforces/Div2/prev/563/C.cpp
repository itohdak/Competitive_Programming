#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

bool arr[100005];
int group[100005];
set<ll> primes;
void Eratosthenes(int N) {
  for(int i=0; i<N; i++) {
    arr[i] = true;
    group[i] = 0;
  }
  int tmp = 0;
  for(int i=2; i<sqrt(N); i++) {
    if(arr[i]) {
      tmp++;
      group[i] = tmp;
      for(int j=0; i*(j+2)<N; j++) {
	arr[i*(j+2)] = false;
	group[i*(j+2)] = tmp;
      }
    }
  }

  for(int i=2; i<N; i++) {
    if(arr[i]) {
      primes.insert(i);
      if(group[i] == 0)
	group[i] = ++tmp;
    }
  }
}

int main() {
  int n;
  cin >> n;
  Eratosthenes(n+1);
  REP(i, 2, n+1)
    cout << group[i] << ' ';
  cout << endl;
  return 0;
}

