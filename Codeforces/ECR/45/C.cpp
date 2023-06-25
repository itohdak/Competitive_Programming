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
  vector<string> S(n);
  for(int i=0; i<n; i++)
    cin >> S[i];
  vector<int> f(6*1e5+1, 0), b(6*1e5+1, 0);
  for(int i=0; i<n; i++){
    string s = S[i];
    int lf = 0, rf = 0;
    int lb = 0, rb = 0;
    for(int i=0; i<s.size(); i++){
      if(s[i] == '('){
	lf++;
      } else {
	if(lf < rf + 1)
	  break;
	else
	  rf++;
      }
      if(i == (int)s.size()-1)
	f[3*1e5 + lf-rf]++;
    }

    for(int i=0; i<s.size(); i++){
      if(s[s.size()-1-i] == '('){
	if(rb < lb + 1)
	  break;
	else
	  lb++;
      } else {
	rb++;
      }
      if(i == (int)s.size()-1)
	b[3*1e5 + lb-rb]++;
    }
  }
  ll ans = 0;
  for(int i=0; i<6*1e5+1; i++)
    ans += (ll)f[i] * (ll)b[6*1e5 - i];
  cout << ans << endl;
  return 0;
}
