#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, K;
  cin >> n >> K;
  vector<int> A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  int ans = 0;
  int same = 0;
  int i = 0;
  while(i < n){
    while(A[i] + K >= A[i+1] && i < n-1){
      if(A[i] == A[i+1])
	same++;
      else
	same = 0;
      i++;
    }
    ans += same;
    same = 0;
    ans++;
    i++;
  }
  cout << ans << endl;
  return 0;
}

