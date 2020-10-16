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
  vector<int> P(n);
  for(int i=0; i<n; i++)
    cin >> P[i];

  for(int i=0; i<n; i++){
    int tmp = i;
    vector<bool> memo(n, false);
    while(!memo[tmp]){
      memo[tmp] = true;
      tmp = P[tmp]-1;
    }
    cout << tmp+1 << ' ';
  }
  cout << endl;
  return 0;
}

