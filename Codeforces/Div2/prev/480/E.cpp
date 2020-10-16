#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, k;
  ll d;
  cin >> n >> k >> d;
  vector<ll> A;
  for(int i=0; i<n; i++){
    ll in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end());
  int ntmp = 1;
  bool ok = true;
  for(int i=1; i<n; i++){
    if((A[i] - A[i-1]) <= d){
      ntmp++;
    } else {
      if(ntmp >= k){
	ntmp = 1;
      } else {
	ok = false;
	break;
      }
    }

    if(i == n-1)
      if(ntmp >= k){
	ntmp = 1;
      } else {
	ok = false;
	break;
      }
  }

  if(ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}

