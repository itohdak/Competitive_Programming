#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  vector<string> S(2);
  for(int i=0; i<2; i++)
    cin >> S[i];
  int ans = 0;
  for(int i=0; i<S[0].size(); i++){
    if(S[0][i] == '0' && S[1][i] == '0'){
      while(1){
	if(i != 0){
	  if(S[0][i-1] == '0' || S[1][i-1] == '0'){
	    if(S[0][i-1] == '0'){
	      S[0][i-1] = 'X';
	      S[0][i] = 'X';
	      S[1][i] = 'X';
	      ans++;
	      break;
	    } else {
	      S[1][i-1] = 'X';
	      S[0][i] = 'X';
	      S[1][i] = 'X';
	      ans++;
	      break;
	    }
	  }
	}
	if(i != (int)S[0].size() - 1){
	  if(S[0][i+1] == '0' || S[1][i+1] == '0'){
	    if(S[0][i+1] == '0'){
	      S[0][i+1] = 'X';
	      S[0][i] = 'X';
	      S[1][i] = 'X';
	      ans++;
	      break;
	    } else {
	      S[1][i+1] = 'X';
	      S[0][i] = 'X';
	      S[1][i] = 'X';
	      ans++;
	      break;
	    }
	  }
	}
	break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

