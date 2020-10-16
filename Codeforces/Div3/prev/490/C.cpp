#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> nalpha(26, 0);
  for(int i=0; i<n; i++)
    nalpha[(int)s[i] - (int)'a']++;
  int start = 26;
  for(int i=0; i<26; i++){
    if(k >= nalpha[i])
      k -= nalpha[i];
    else {
      start = i;
      break;
    }
  }
  for(int i=0; i<n; i++){
    if((int)s[i] - (int)'a' > start)
      cout << s[i];
    else if((int)s[i] - (int)'a' == start){
      if(k > 0)
	k--;
      else
	cout << s[i];
    }
  }
  cout << endl;
  return 0;
}

