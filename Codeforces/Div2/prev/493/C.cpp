#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int zero_or_one(char c){
  if(c == '0')
    return 0;
  else
    return 1;
}
int main(){
  int n;
  ll x, y;
  cin >> n >> x >> y;
  string a;
  cin >> a;
  int prev = zero_or_one(a[0]);
  int zeros = 0;
  if(prev == 0)
    zeros = 1;
  for(int i=1; i<n; i++){
    if(zero_or_one(a[i]) == 0 && zero_or_one(a[i]) != prev)
      zeros++;
    prev = zero_or_one(a[i]);
  }
  if(zeros == 0)
    cout << 0 << endl;
  else
    if(x < y)
      cout << (zeros - 1) * x + y << endl;
    else
      cout << zeros * y << endl;
  return 0;
}

