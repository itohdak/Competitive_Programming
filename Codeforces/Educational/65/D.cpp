#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ret = "";
  int r = 0, b = 0;
  for(int i=0; i<n; i++) {
    if(s[i] == '(') {
      if(r < b) {
	ret += '0';
	r++;
      } else {
	ret += '1';
	b++;
      }
    } else {
      if(r < b) {
	ret += '1';
	b--;
      } else {
	ret += '0';
	r--;
      }
    }
  }
  cout << ret << endl;
  return 0;
}

