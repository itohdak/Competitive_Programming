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
  vector<int> num(2);
  for(int i=0; i<n; i++) {
    cin >> A[i];
    if(A[i] == 1)
      num[0]++;
    else
      num[1]++;
  }
  if(num[0] > 0 && num[1] > 0) {
    cout << 2 << ' ';
    num[1]--;
    cout << 1 << ' ';
    num[0]--;
    for(int i=0; i<num[1]; i++)
      cout << 2 << ' ';
    for(int i=0; i<num[0]; i++)
      cout << 1 << ' ';
    cout << endl;
  } else if(num[0] > 0) {
    for(int i=0; i<num[0]; i++)
      cout << 1 << ' ';
    cout << endl;
  } else if(num[1] > 0) {
    for(int i=0; i<num[1]; i++)
      cout << 2 << ' ';
    cout << endl;
  }
  return 0;
}

