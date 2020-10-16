#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n;
  string s;
  cin >> n >> s;
  int tg[26*26];
  for(int i=0; i<26*26; i++)
    tg[i] = 0;
  for(int i=0; i<n-1; i++){
    tg[((int)s[i]-65) * 26 + ((int)s[i+1]-65)]++;
  }
  int max = 0;
  int max_index = -1;
  for(int i=0; i<26*26; i++){
    if(tg[i] > max){
      max = tg[i];
      max_index = i;
    }
  }
  cout << char(65+max_index/26) << char(65+max_index%26) << endl;
  return 0;
}

