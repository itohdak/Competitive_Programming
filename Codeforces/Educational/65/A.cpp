#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int t;
  cin >> t;
  for(int i=0; i<t; i++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ret = false;
    for(int j=0; j<n; j++)
      if(s[j] == '8' && n-j >= 11)
	ret = true;
    if(ret)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

