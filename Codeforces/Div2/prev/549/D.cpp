#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <climits>

using namespace std;
#define ll long long

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

int main(){
  ll n, k;
  cin >> n >> k;
  ll a, b;
  cin >> a >> b;
  ll x = LLONG_MAX;
  ll y = -1;
  for(ll i=0; i<=n; i++) {
    ll l, ans;
    l = abs(b - a) + i * k;
    if(l != 0) {
      ans = n*k / gcd(l, n*k);
      x = min(x, ans);
      y = max(y, ans);
    }
    if(i > 0) {
      l = - b - a + i * k;
      if(l != 0) {
	ans = n*k / gcd(l, n*k);
	x = min(x, ans);
	y = max(y, ans);
      }
    }
  }
  cout << x << ' ' << y << endl;
  return 0;
}

