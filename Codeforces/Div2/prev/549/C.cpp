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
  vector<pair<int, int> > resp(n, make_pair(-1, 1));
  for(int i=0; i<n; i++) {
    int p, c;
    cin >> p >> c;
    p--;
    if(c == 0) {
      resp[i].first = 0;
      resp[p].second = 0;
    } else {
      resp[i].first = 1;
      if(resp[p].second == -1)
	resp[p].second = 1;
    }
  }
  vector<int> ans;
  for(int i=0; i<n; i++) {
    if(resp[i].first == 1 && resp[i].second == 1)
      ans.push_back(i+1);
  }
  if(ans.size() == 0)
    cout << -1 << endl;
  else
    for(int i=0; i<ans.size(); i++) {
      cout << ans[i];
      if(i != ans.size()-1)
	cout << ' ';
      else
	cout << endl;
    }
  return 0;
}

