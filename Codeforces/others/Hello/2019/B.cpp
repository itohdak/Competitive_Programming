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
  vector<int> A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  bool ret = false;
  for(int i=0; i<(int)pow(2,n); i++) {
    int tmp = i;
    int sum = 0;
    for(int j=0; j<n; j++) {
      if(tmp % 2 == 0)
	sum += A[j];
      else
	sum -= A[j];
      tmp /= 2;
    }
    if(sum % 360 == 0)
      ret = true;
  }
  if(ret)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

