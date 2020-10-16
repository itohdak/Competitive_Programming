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
  vector<int> A(2*n);
  for(int i=0; i<2*n; i++)
    cin >> A[i];
  int ans = 0;
  for(int i=0; i<2*n; i+=2){
    int pos = find(A.begin()+i+1, A.end(), A[i]) - A.begin();
    ans += pos - i - 1;
    for(int j=pos; j>=i; j--)
      A[j] = A[j-1];
  }
  cout << ans << endl;
  return 0;
}

