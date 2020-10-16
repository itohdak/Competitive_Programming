#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool test(ll n, ll k){
  ll m = n;
  ll v = 0, p = 0;
  while(m > 0){
    if(m < k){
      v += m;
      m -= m;
    } else {
      v += k;
      m -= k;
    }
    p += m / 10;
    m -= m / 10;
  }
  return v >= p;
}

int main(){
  ll n;
  cin >> n;
  ll h = (ll)ceil(1.0 * n / 2);
  ll l = 1;
  while(l < h){
    ll mid = (h + l) / 2;
    if(test(n, mid))
      h = mid;
    else
      l = mid+1;
  }
  cout << h << endl;
  return 0;
}

