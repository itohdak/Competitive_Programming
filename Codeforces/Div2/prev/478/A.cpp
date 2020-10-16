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
  vector< vector<bool> > ret;
  for(int i=0; i<n; i++){
    vector<bool> tmp(26, false);
    string in;
    cin >> in;
    for(int j=0; j<in.size(); j++){
      tmp[int(in[j] - 'a')] = true;
    }
    if(ret.size() == 0)
      ret.push_back(tmp);
    bool tmp2 = false;
    for(int j=0; j<ret.size(); j++){
      bool tmp3 = true;
      for(int k=0; k<26; k++){
	if(ret[j][k] != tmp[k]){
	  tmp3 = false;
	  break;
	}
      }
      if(tmp3){
	tmp2 = true;
	break;
      }
    }
    if(!tmp2){
      ret.push_back(tmp);
    }
  }
  cout << ret.size() << endl;
  return 0;
}

