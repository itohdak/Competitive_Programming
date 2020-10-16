#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll n, m;
  int a, b;
  cin >> n >> m >> a >> b;
  cout << min(((n / m + 1) * m - n) * a, (n - n / m * m) * b) << endl;
  return 0;
}

