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
  vector<int> grade(n);
  vector<int> up(n);
  int sum = 0;
  for(int i=0; i<n; i++){
    cin >> grade[i];
    up[i] = 5 - grade[i];
    sum += grade[i];
  }
  sort(up.begin(), up.end(), greater<int>());
  int ret = 0;
  while(4.5 * n - sum > 0){
    sum += up[ret];
    ret++;
  }
  cout << ret << endl;

  return 0;
}

