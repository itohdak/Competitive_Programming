#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, t;
  cin >> n >> t;
  vector<int> S(n), D(n);
  for(int i=0; i<n; i++)
    cin >> S[i] >> D[i];
  int minTime = 1000000;
  int minInd = -1;
  for(int i=0; i<n; i++) {
    int tmpTime = max(0, (int)ceil(1.0 * (t - S[i]) / D[i])) * D[i] + S[i];
    if(minTime > tmpTime) {
      minTime = tmpTime;
      minInd = i;
    }
  }
  cout << minInd + 1 << endl;
  return 0;
}

