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
  vector<int> k(n);
  int left = 0, right = 0;
  for(int i=0; i<n; i++) {
    cin >> k[i];
    if(k[i] == 0) {
      left = i + 1;
    } else {
      right = i + 1;
    }
  }
  cout << min(left, right) << endl;
  return 0;
}

