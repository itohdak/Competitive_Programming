#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, C, N;
  cin >> A >> B >> C >> N;
  int passed = A + B - C;
  if(passed >= 0 && A < N && B < N && C < N && A >= C && B >= C){
    if(passed < N)
      cout << N - passed << endl;
    else
      cout << -1 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}

