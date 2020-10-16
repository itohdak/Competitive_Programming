#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  int d = a, v = b;
  for(int i=0; i<=n; i++) {
    if(d == v) {
      cout << "YES" << endl;
      return 0;
    }
    if(d == x || v == y) break;
    d = d == n ? 1 : d+1;
    v = v == 1 ? n : v-1;
  }
  cout << "NO" << endl;
  return 0;
}

