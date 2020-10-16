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
  string a, b;
  cin >> a >> b;
  ll zero_zero = 0; // 0
  ll zero_one = 0; // 1
  ll one_zero = 0; // 1
  ll one_one = 0; // 1
  for(int i=0; i<n; i++){
    if(a[i] == '0' && b[i] == '0')
      zero_zero++;
    else if(a[i] == '0' && b[i] == '1')
      zero_one++;
    else if(a[i] == '1' && b[i] == '0')
      one_zero++;
    else if(a[i] == '1' && b[i] == '1')
      one_one++;
  }
  cout << zero_zero * (one_zero + one_one) + zero_one * one_zero << endl;
  return 0;
}

