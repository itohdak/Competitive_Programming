#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <climits>

using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  int l = -1, r = n;
  while(r - l > 1) {
    int mid = (l + r) / 2;
    if(A[mid] < 0)
      l = mid;
    else
      r = mid;
  }
  int minus = l;
  ll ans = 0;
  // 0 <= x < y
  for(int i=minus+1; i<n; i++) {
    int l = i, r = n;
    while(r - l > 1) {
      int mid = (l + r) / 2;
      if(A[mid] <= A[i] * 2)
	l = mid;
      else
	r = mid;
    }
    ans += l - i;
  }
  // x < 0 <= y
  for(int i=0; i<minus+1; i++) {
    int l = minus, r = n;
    while(r - l > 1) {
      int mid = (l + r) / 2;
      if(A[mid] <= -2 * A[i])
	l = mid;
      else
	r = mid;
    }
    int l1 = l;
    l = minus, r = n;
    while(r - l > 1) {
      int mid = (l + r) / 2;
      if(A[mid] < -0.5* A[i])
	l = mid;
      else
	r = mid;
    }
    ans += l1 - l;
  }
  // x < y < 0
  for(int i=0; i<minus+1; i++) {
    int l = i, r = minus+1;
    while(r - l > 1) {
      int mid = (l + r) / 2;
      if(2 * A[mid] <= A[i])
	l = mid;
      else
	r = mid;
    }
    ans += l - i;
  }
  cout << ans << endl;
  return 0;
}

