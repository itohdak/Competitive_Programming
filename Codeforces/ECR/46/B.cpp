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
  vector<ll> A(n+2, 0);
  for(int i=0; i<n; i++)
    cin >> A[i+1];
  A[n+1] = m;
  vector<ll> diff(n+1, 0);
  for(int i=0; i<n+1; i++)
    diff[i] = A[i+1] - A[i];
  vector<ll> even(n+1, 0);
  even[0] = diff[0];
  vector<ll> odd(n+1, 0);
  for(int i=0; i<n+1; i++){
    if(i % 2 == 0){
      if(i != 0){
	even[i] += even[i-1] + diff[i];
	odd[i] += odd[i-1];
      }
    } else {
      even[i] += even[i-1];
      odd[i] += odd[i-1] + diff[i];
    }
  }
  // for(int i=0; i<n+1; i++)
  //   cout << diff[i] << ' ';
  // cout << endl;
  // for(int i=0; i<n+1; i++)
  //   cout << even[i] << ' ';
  // cout << endl;
  // for(int i=0; i<n+1; i++)
  //   cout << odd[i] << ' ';
  // cout << endl;
  ll max = even[n];
  for(int i=0; i<n+1; i++){
    if(even[i] + odd[n] - odd[i] - 1 > max)
      max = even[i] + odd[n] - odd[i] - 1;
  }
  cout << max << endl;
  return 0;
}

