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
  int target = 0;
  int up = 0;
  for(int i=0; i<n; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(i == 0)
      target = a + b + c + d;
    else
      if(a + b + c + d > target)
	up++;
  }
  cout << up+1 << endl;
  return 0;
}

