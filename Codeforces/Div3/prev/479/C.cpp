#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> A;
  for(int i=0; i<n; i++){
    ll in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end());
  if(k == n){
    cout << A[n-1] << endl;
  } else if(k == 0){
    if(A[0] == 1)
      cout << -1 << endl;
    else
      cout << A[0]-1 << endl;
  } else if(A[k-1] == A[k]){
    cout << -1 << endl;
  } else {
    cout << A[k-1] << endl;
  }
  return 0;
}

