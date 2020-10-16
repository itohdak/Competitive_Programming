#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, m;
  cin >> n >> m;
  int A[n][m];
  int B[m];
  for(int i=0; i<m; i++)
    B[i] = 0;
  for(int i=0; i<n; i++){
    string in;
    cin >> in;
    for(int j=0; j<m; j++){
      A[i][j] = (int)in[j]-48;
      if(A[i][j] == 1)
	B[j] += 1;
    }
  }

  bool ok = false;
  for(int i=0; i<n; i++){
    bool tmp = true;
    for(int j=0; j<m; j++){
      if(A[i][j] == 1 && B[j] == 1){
	tmp = false;
	break;
      }
    }
    if(tmp){
      ok = true;
      break;
    }
  }
  if(ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

