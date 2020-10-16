#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> A(n, 0LL);
  for(int i=0; i<n; i++){
    ll in;
    cin >> in;
    if(i == 0)
      A[i] = in;
    else
      A[i] = A[i-1] + in;
  }
  for(int i=0; i<n; i++){
    A[i] /= m;
  }
  for(int i=0; i<n; i++){
    if(i == 0)
      cout << A[i] << ' ';
    else
      cout << A[i] - A[i-1] << ' ';
  }
  cout << endl;
  return 0;
}

