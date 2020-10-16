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
  vector<int> P(n, 0);
  string S(n, '0');
  for(int i=0; i<m; i++) {
    int a;
    cin >> a;
    P[a-1]++;
    S[a-1] = '1';
    if(S == string(n, '1')) {
      cout << '1';
      for(int j=0; j<n; j++) {
	P[j]--;
	if(P[j] > 0)
	  S[j] = '1';
	else
	  S[j] = '0';
      }
    } else
      cout << '0';
  }
  cout << endl;
  return 0;
}

