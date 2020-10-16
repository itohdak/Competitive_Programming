#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int q;
  cin >> q;
  for(int i=0; i<q; i++) {
    ll l, r, d;
    cin >> l >> r >> d;
    if(d < l)
      cout << d << endl;
    else if(d <= r)
      cout << (r / d + 1) * d << endl;
    else
      cout << d << endl;
  }
  return 0;
}

