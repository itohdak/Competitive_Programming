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
  int mini = min_element(A.begin(), A.end()) - A.begin();
  if(n == 1 || (n == 2 && A[0] == A[1]))
    cout << -1 << endl;
  else{
    cout << n-1 << endl;
    for(int i=0; i<n; i++)
      if(i != mini)
	cout << i+1 << ' ';
    cout << endl;
  }
  return 0;
}

