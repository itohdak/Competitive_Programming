#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n;
  cin >> n;
  vector<ll> L(n), R(n);
  for(int i=0; i<n; i++)
    cin >> L[i] >> R[i];
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  L.push_back(1e+18+1);
  R.push_back(1e+18+1);
  vector<ll> A(n, 0LL);
  ll l = 0, r = 0;
  int cnt = 0;
  ll prev;
  while(l < n || r < n){
    if(L[l] < R[r]){
      if(l != 0)
	if(cnt != 0)
	  A[cnt-1] += L[l] - prev - 1;
      ll tmp = L[l];
      while(L[l] == tmp && l < n){
	cnt++; l++;
      }
      if(cnt != 0)
      	A[cnt-1]++;
      prev = tmp;
    } else if(L[l] == R[r]){
      if(cnt != 0){
	A[cnt-1] += L[l] - prev - 1;
      }
      ll tmp = L[l];
      while(L[l] == tmp && l < n){
	cnt++; l++;
      }
      if(cnt != 0)
      	A[cnt-1]++;
      while(R[r] == tmp && r < n){
	cnt--; r++;
      }
      prev = tmp;
    } else if(L[l] > R[r]){
      if(cnt != 0)
      	A[cnt-1]++;
      if(cnt != 0)
	A[cnt-1] += R[r] - prev - 1;
      ll tmp = R[r];
      while(R[r] == tmp && r < n){
	cnt--; r++;
      }
      prev = tmp;
    }
  }
  for(int i=0; i<n; i++)
    cout << A[i] << ' ';
  cout << endl;
  return 0;
}

