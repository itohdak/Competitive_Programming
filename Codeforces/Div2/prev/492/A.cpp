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
  cin >> n;
  ll ans = 0;
  while(n >= 100){
    ans += 1;
    n -= 100;
  }
  while(n >= 20){
    ans += 1;
    n -= 20;
  }
  while(n >= 10){
    ans += 1;
    n -= 10;
  }
  while(n >= 5){
    ans += 1;
    n -= 5;
  }
  while(n >= 1){
    ans += 1;
    n -= 1;
  }
  cout << ans << endl;
  return 0;
}

