#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, m, h;
  cin >> n >> m >> h;
  vector<int> A(m), B(n);
  vector<vector<int> > H(n, vector<int>(m)), Hret(n, vector<int>(m));
  for(int i=0; i<m; i++)
    cin >> A[i];
  for(int i=0; i<n; i++)
    cin >> B[i];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> H[i][j];
      if(H[i][j] == 1)
	Hret[i][j] = min(A[j], B[i]);
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << Hret[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}

