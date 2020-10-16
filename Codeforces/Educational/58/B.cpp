#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int l = 0, r = n-1;
  while(l < n && s[l] != '[')
    l++;
  while(r >= 0 && s[r] != ']')
    r--;
  if(r < l) {
    cout << -1 << endl;
  } else {
    int l2 = l, r2 = r;
    while(l2 < r && s[l2] != ':')
      l2++;
    while(r2 >= l && s[r2] != ':')
      r2--;
    if(r2 <= l2) {
      cout << -1 << endl;
    } else {
      int ret = 4;
      for(int i=l2+1; i<r2; i++) {
	if(s[i] == '|') {
	  ret++;
	}
      }
      cout << ret << endl;
    }
  }
  return 0;
}

