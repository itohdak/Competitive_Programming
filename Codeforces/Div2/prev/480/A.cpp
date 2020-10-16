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
  vector<int> P;
  for(int i=0; i<n/2; i++){
    int p;
    cin >> p;
    P.push_back(p);
  }
  sort(P.begin(), P.end());
  int ret1 = 0;
  int ret2 = 0;
  for(int i=0; i<P.size(); i++){
    ret1 += abs((i+1)*2 - P[i]);
    ret2 += abs(i*2+1 - P[i]);
  }
  cout << min(ret1, ret2) << endl;
  return 0;
}

