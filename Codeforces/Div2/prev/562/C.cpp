#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool isAvailable(vector<int> v, int n, int m, int t) {
  vector<int> tmp(1, 0);
  tmp.insert(tmp.end(), v.begin(), v.end());
  for(int i=1; i<n; i++) {
    if(tmp[i-1] <= tmp[i] && tmp[i] <= tmp[i+1])
      continue;
    else {
      if(tmp[i-1] > tmp[i]) {
	if(tmp[i-1] - tmp[i] <= m) tmp[i] = tmp[i-1];
	else return false;
	if(tmp[i] > tmp[i+1]) {
	  if(tmp[i] - tmp[i+1] <= m) tmp[i+1] = tmp[i];
	  else return false;
	}
      } else {
	if(tmp[i-1] + m - tmp[i] <= m) tmp[i] = tmp[i-1];
	if(tmp[i] > tmp[i+1]) {
	  if(tmp[i] - tmp[i+1] <= m) tmp[i+1] = tmp[i];
	  else return false;
	}
      }
    }
  }
  for(int i=0; i<n; i++)
    cout << v[i] << ' ';
  cout << endl;
  return true;
}
int binary_search(vector<int> v, int n, int m) {
  int l = 0, r = m+1;
  while(r - l > 1) {
    int mid = (l + r) / 2;
    if(!isAvailable(v, n, m, mid))
      l = mid;
    else
      r = mid;
  }
  return l;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  cout << binary_search(A, n, m) << endl;
  return 0;
}

