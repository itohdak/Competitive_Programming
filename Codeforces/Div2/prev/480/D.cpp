#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll n, H;
  cin >> n >> H;
  ll ret = 0;
  ll tmp = 1;
  ll min = n;
  while(n > 0){
    if(ret + ceil(n / tmp) < min)
      min = ret + ceil(1.0 * n / tmp);

    if(n >= tmp){
      n -= tmp;
      if(tmp < H)
	tmp++;
      ret++;
    } else {
      break;
    }
  }
  cout << ret << endl;
  return 0;
}

