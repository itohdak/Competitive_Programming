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
  vector<int> A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  int left = 0;
  int lend = n-1;
  for(int i=0; i<n; i++){
    if(A[i] <= k){
      left++;
    } else {
      lend = i;
      break;
    }
  }
  int right = 0;
  int rend = 0;
  for(int i=n-1; i>=0; i--){
    if(A[i] <= k){
      right++;
    } else {
      rend = i;
      break;
    }
  }
  if(lend > rend)
    cout << n << endl;
  else
    cout << left + right << endl;
  return 0;
}

