#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll n;
  int k;
  cin >> n >> k;
  for(int i=0; i<k; i++){
    if(n % 10 == 0){
      n /= 10;
    } else {
      n -= 1;
    }
  }
  cout << n << endl;
  return 0;
}

