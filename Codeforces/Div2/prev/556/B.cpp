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
  vector<vector<bool> > B(n, vector<bool>(n, false));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) {
      char in;
      cin >> in;
      B[i][j] = (in == '#');
    }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(i == 0 || i == n-1 || j == 0 || j == n-1)
	continue;
      if(!B[i][j] && !B[i-1][j] && !B[i][j-1] && !B[i+1][j] && !B[i][j+1]) {
	B[i][j] = true;
	B[i-1][j] = true;
	B[i][j-1] = true;
	B[i+1][j] = true;
	B[i][j+1] = true;
      }
    }
  }
  bool ans = true;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(!B[i][j]) {
	ans = false;
	break;
      }
  if(ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

