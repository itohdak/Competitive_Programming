#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int t;
  cin >> t;
  vector<int> A(t);
  vector<int> N(t, 0);
  int max = 0;
  for(int i=0; i<t; i++){
    cin >> A[i];
    N[A[i]]++;
    if(A[i] > max)
      max = A[i];
  }
  for(int i=1; i<=t/max; i++){
    if(t % i == 0){
      for(int j=0; j<i; j++){
	vector<int> Num(t, 0);
	int X = max - j, Y = j;
	for(int x=0; x<t/i; x++){
	  for(int y=0; y<i; y++){
	    Num[abs(x-X)+abs(y-Y)]++;
	  }
	}
	bool ok = true;
	for(int k=0; k<t; k++){
	  if(N[k] != Num[k]){
	    ok = false;
	    break;
	  }
	}
	if(ok){
	  cout << i << ' ' << t/i << endl;
	  cout << Y+1 << ' ' << X+1 << endl;
	  return 0;
	}
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

