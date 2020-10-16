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
  vector<ll> A;
  cin >> n;
  for(int i=0; i<n; i++){
    ll in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end());
  ll start = -1;
  for(int i=0; i<n; i++){
    ll tmp = A[i];
    if(!(((tmp % 2 == 0 && find(A.begin(), A.end(), A[i]/2) != A.end()) ||
	find(A.begin(), A.end(), A[i]*3) != A.end()))){
      start = tmp;
      break;
    }
  }
  cout << start << ' ';
  ll tmp = start;
  for(int i=0; i<n-1; i++){
    if(tmp % 3 == 0){
      if(find(A.begin(), A.end(), tmp/3) != A.end()){
	cout << tmp / 3 << ' ';
	tmp = tmp / 3;
      } else {
	cout << tmp * 2 << ' ';
	tmp = tmp * 2;
      }
    } else {
      cout << tmp * 2 << ' ';
      tmp = tmp * 2;
    }
  }
  cout << endl;
  return 0;
}

