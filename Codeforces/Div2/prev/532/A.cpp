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
  vector<int> A(k, 0);
  int sum = 0;
  for(int i=0; i<n; i++) {
    int a;
    cin >> a;
    A[i%k] += a;
    sum += a;
  }
  int ans = 0;
  for(int i=0; i<k; i++)
    if(ans < abs(sum - A[i]))
      ans = abs(sum - A[i]);
  cout << ans << endl;
  return 0;
}

