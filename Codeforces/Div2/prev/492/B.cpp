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
  cin >> n;
  vector<ll> A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  for(int i=0; i<n; i++)
    A[i] -= i;
  int min = 1e+9;
  int min_i = -1;

  for(int i=0; i<n; i++)
    if(A[i] < min){
      min = A[i];
      min_i = i;
    }
  for(int i=0; i<n; i++)
    A[i] -= (int)ceil(1.0 * min / n) * n;
  for(int i=0; i<n; i++)
    if(A[i] <= 0){
      cout << i+1 << endl;
      break;
    }
  return 0;
}

