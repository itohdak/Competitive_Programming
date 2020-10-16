#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool test(vector<ll> X, int n, int k, ll z) {
  bool ret = true;
  for(int i=0; i<k; i++)
    if(X[n-k+i] - X[i] < z)
      ret = false;
  return ret;
}

int main(){
  int n;
  ll z;
  cin >> n >> z;
  vector<ll> X(n);
  for(int i=0; i<n; i++)
    cin >> X[i];
  sort(X.begin(), X.end());
  int l = -1, r = n/2+1;
  while(r - l > 1) {
    int mid = (l + r) / 2;
    if(test(X, n, mid, z))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}

