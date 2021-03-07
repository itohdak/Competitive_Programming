#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string s1;
  bool ret = false;
  cin >> s1;
  for(int i=0; i<5; i++) {
    string s;
    cin >> s;
    if(s1[0] == s[0] || s1[1] == s[1])
      ret = true;
  }
  if(ret)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

