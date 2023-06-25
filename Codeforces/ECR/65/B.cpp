#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <map>

using namespace std;
#define ll long long

int main() {
  string S[] = {"? 1 2", "? 1 3", "? 1 4", "? 1 5"};
  vector<int> res(4);
  map<int, vector<int> > mp;
  mp[5] = vector<int>(); mp[7] = vector<int>(); mp[23] = vector<int>();
  int special[] = {5, 7, 23};
  int special_ans[] = {15, 42, 23};
  int all[] = {4, 8, 15, 16, 23, 42};
  for(int i=0; i<4; i++) {
    cout << S[i] << endl;
    cin >> res[i];
    for(int j=0; j<3; j++) {
      if(res[i] % special[j] == 0) {
	mp[special[j]].push_back(i);
      }
    }
  }
  vector<int> ans(6, 0);
  map<int, bool> used;
  for(int i=0; i<6; i++)
    used[all[i]] = false;
  bool flag = false;
  for(int j=0; j<3; j++) {
    int size = mp[special[j]].size();
    if(size == 0) {
      ans[5] = special_ans[j];
    } else if(size == 1) {
      ans[mp[special[j]][0]+1] = special_ans[j];
      ans[0] = res[mp[special[j]][0]] / special_ans[j];
      used[ans[0]] = true;
      if(!flag) {
	for(int i=1; i<5; i++) {
	  ans[i] = res[i-1] / ans[0];
	  used[ans[i]] = true;
	}
	flag = true;
      }
    } else {
      ans[0] = special_ans[j];
      if(!flag) {
	for(int i=1; i<5; i++) {
	  ans[i] = res[i-1] / ans[0];
	  used[ans[i]] = true;
	}
	flag = true;
      }
    }
  }
  if(ans[5] == 0)
    for(int i=0; i<6; i++)
      if(!used[all[i]])
	ans[5] = all[i];
  cout << "! ";
  for(int i=0; i<6; i++)
    cout << ans[i] << ' ';
  cout << endl;
  return 0;
}

