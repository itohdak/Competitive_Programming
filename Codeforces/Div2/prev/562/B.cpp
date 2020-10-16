#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <set>

using namespace std;
#define ll long long

void dfs(vector<pair<int, int> >& AB, int& x, int& y, int i, bool& res) {
  if(i == 0) {
    x = AB[i].first;
    dfs(AB, x, y, i+1, res);
    if(res) return;
    x = AB[i].second;
    dfs(AB, x, y, i+1, res);
  } else if(i == AB.size()) {
    res = true;
    return;
  } else {
    // cout << i << ": " << x << ' ' << y << endl;
    if(y == 0) {
      if(AB[i].first == x || AB[i].second == x)
	dfs(AB, x, y, i+1, res);
      else {
	y = AB[i].first;
	dfs(AB, x, y, i+1, res);
	if(res) return;
	y = AB[i].second;
	dfs(AB, x, y, i+1, res);
	if(res) return;
	y = 0;
      }
    } else {
      if(AB[i].first == x || AB[i].second == x ||
	 AB[i].first == y || AB[i].second == y)
	dfs(AB, x, y, i+1, res);
      else
	return;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > AB;
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    AB.push_back(make_pair(a, b));
  }
  int x = 0, y = 0;
  bool res = false;
  dfs(AB, x, y, 0, res);
  if(res)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

