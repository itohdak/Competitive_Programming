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
  cin >> n >> k;
  int memo[100];
  for(int i=0; i<100; i++)
    memo[i] = 0;
  int dis = 0;
  for(int i=0; i<n; i++){
    int in;
    cin >> in;
    in--;
    if(memo[in] == 0){
      dis++;
      memo[in] = i+1;
    }
  }

  if(k <= dis){
    cout << "YES" << endl;
    int i = 0;
    while(k > 0 && i < 100){
      if(memo[i] != 0){
	cout << memo[i] << ' ';
	k--;
      }
      i++;
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

