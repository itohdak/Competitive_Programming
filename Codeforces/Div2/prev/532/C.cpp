#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define PI 3.141592653589

int main(){
  int n, r;
  cin >> n >> r;
  double s = sin(PI / n);
  cout << fixed << setprecision(7) << s * r / (1.0 - s) << endl;
  return 0;
}

