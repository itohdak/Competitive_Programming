#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> A(n), N(n, 0);
  for(int i=0; i<n; i++){
    cin >> A[i];
    N[A[i] % m]++;
  }
  ll ans = 0;
  for(int i=0; i<n; i++){
    if(N[A[i] % m] > n / m){
      for(int j=1; j<=m; j++){
	if(N[(A[i] + j) % m] < n / m){
	  ans += j;
	  N[A[i] % m]--;
	  A[i] += j;
	  N[A[i] % m]++;
	  break;
	}
      }
    }
  }
  cout << ans << endl;
  for(int i=0; i<n; i++)
    cout << A[i] << ' ';
  cout << endl;
  return 0;
}

