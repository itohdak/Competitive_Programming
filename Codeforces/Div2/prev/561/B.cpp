#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}

int main() {
  int k;
  cin >> k;
  find_divisor(k);
  char vowel[] = {'a', 'e', 'i', 'o', 'u'};
  for(int i=0; i<divisor.size(); i++) {
    if(divisor[i] >= 5 && k / divisor[i] >= 5) {
      int row = divisor[i], col = k / divisor[i];
      for(int r=0; r<row; r++) {
	int tmp = r % 5;
	for(int c=0; c<col; c++, tmp++, tmp%=5) {
	  cout << vowel[tmp];
	}
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

