#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <string>

using namespace std;
#define ll long long

bool comp(string s, string t){
  return s.size() <= t.size();
}

int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  vector<ll> T(n, 0LL);
  for(int i=0; i<n; i++){
    cin >> S[i];
    for(int j=S[i].size()-1; j>=0; j--){
      T[i] += ((int)S[i][j] - (int)'a') * pow(26, S[i].size()-1-j);
    }
  }
  sort(S.begin(), S.end(), comp);
  sort(T.begin(), T.end());
  bool ok = true;
  for(int i=1; i<n; i++){
    if(S[i].size() == S[i-1].size()){
      if(T[i] != T[i-1]){
	ok = false;
	break;
      }
    } else {
      bool found = false;
      for(int j=0; j<=S[i].size()-S[i-1].size(); j++){
	if(// S[i].substr(j, S[i-1].size()) == S[i-1]
	   (T[i] / (ll)pow(26, j)) % (ll)pow(26, S[i-1].size()) == T[i-1]
	   ){
	  found = true;
	  break;
	}
      }
      if(!found){
	ok = false;
	break;
      }
    }
  }
  if(ok){
    cout << "YES" << endl;
    for(int i=0; i<n; i++)
      cout << S[i] << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}

