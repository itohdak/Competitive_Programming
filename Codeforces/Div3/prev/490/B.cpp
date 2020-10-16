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
  cin >> n;
  string s;
  cin >> s;
  int pre_pos[n];
  int pos[n];
  for(int i=0; i<n; i++){
    pre_pos[i] = i;
    pos[i] = i;
  }
  for(int i=1; i<=n; i++){
    if(n % i == 0){
      for(int j=0; j<i; j++){
	pos[j] = pre_pos[i - j - 1];
      }
      for(int j=0; j<n; j++){
	pre_pos[j] = pos[j];
      }
      // for(int j=0; j<n; j++)
      // 	cout << s[pos[j]];
      // cout << endl;
    }
  }
  for(int i=0; i<n; i++)
    cout << s[pos[i]];
  cout << endl;

  return 0;
}

