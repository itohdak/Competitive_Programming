#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <functional>

using namespace std;
#define ll long long

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n-i; j++){
      for(int k=0; k<=n-i-j; k++){
	ans++;
      }}}
  cout << ans << endl;
  return 0;
}

