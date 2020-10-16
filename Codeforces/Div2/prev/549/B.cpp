#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll productOfDigits(ll n) {
  ll ret = 1;
  while(n > 0) {
    ret *= (n % 10);
    n /= 10;
  }
  return ret;
}

int main(){
  ll n;
  cin >> n;
  return 0;
}

