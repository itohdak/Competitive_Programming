#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int s;
  string S;
  cin >> s >> S;
  int N = S.size();
  if(N % 2 == 1) {
    cout << ":(" << endl;
    return 0;
  }
  int nUnknown = 0;
  int nLeft = 0, nRight = 0;
  for(int i=0; i<N; i++) {
    if(S[i] == '?')
      nUnknown++;
    else if(S[i] == '(')
      nLeft++;
    else
      nRight++;
  }
  int nLeftNew = N / 2 - nLeft;
  int cnt = 0;
  for(int i=0; i<N; i++) {
    if(S[i] == '?') {
      if(nLeftNew > 0) {
	S[i] = '(';
	cnt++;
	nLeftNew--;
      } else {
	S[i] = ')';
	cnt--;
      }
    } else if(S[i] == '(') {
      cnt++;
    } else {
      cnt--;
    }
    if(i != N-1 && cnt <= 0) {
      cout << ":(" << endl;
      break;
    }
    if(i == N-1) {
      if(cnt != 0) {
	cout << ":(" << endl;
	break;
      } else {
	cout << S << endl;
	break;
      }
    }
  }
  return 0;
}

