#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  string s, t;
  cin >> s >> t;
  vector<int> I;
  for(int i=0; i<n-m+1; i++){
    if(t == s.substr(i, m))
      I.push_back(i);
  }
  // for(int j=0; j<I.size(); j++)
  //   cout << I[j] << ' ';
  // cout << endl;
  for(int i=0; i<q; i++){
    int l, r;
    cin >> l >> r;
    l--; r--;
    int ans = 0;
    for(int j=0; j<I.size(); j++){
      if(I[j] < l)
	continue;
      else if(I[j]+m-1 > r)
	break;
      else
	ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

