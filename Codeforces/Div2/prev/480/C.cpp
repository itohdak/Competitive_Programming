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
  ll l;
  cin >> n >> k >> l;
  vector<ll> A;
  for(int i=0; i<n*k; i++){
    ll in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end());

  ll sum = 0;
  int i = 0;
  while(i < n*k && A[i] <= A[0] + l)
    i++;

  if(i < n){
    cout << 0 << endl;
  } else {
    for(int j=0; j<i-n; j+=k){
      sum += A[j];
      n--;
    }
    sum += accumulate(A.begin()+i-n, A.begin()+i, 0LL);
    cout << sum << endl;
  }

  return 0;
}
