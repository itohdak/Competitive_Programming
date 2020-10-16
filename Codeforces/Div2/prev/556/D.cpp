#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <stack>

using namespace std;
#define ll long long

int main(){
  int n, q;
  cin >> n >> q;
  string WoU;
  cin >> WoU;
  vector<vector<int> > cpos(26, vector<int>(n+1, n+1));
  for(int c=0; c<26; c++) {
    char target = 'a' + c;
    int tmp = n+1;
    for(int i=n; i>0; i--) {
      cpos[c][i] = tmp;
      if(WoU[i-1] == target)
	tmp = i-1;
    }
    cpos[c][0] = tmp;
  }
  // for(int c=0; c<26; c++) {
  //   for(int i=0; i<cpos[c].size(); i++) {
  //     cout << cpos[c][i] << ' ';
  //   }
  //   cout << endl;
  // }
  vector<bool> occupied(n, false);
  vector<stack<int> > S(3, stack<int>());
  vector<int> tmpPos(3, -1);
  for(int i=0; i<q; i++) {
    char op, c;
    int num;
    cin >> op;
    cin >> num;
    if(op == '+') {
      cin >> c;
      int cIdx = (int)(c-'a');
      int tmp = tmpPos[num-1];
      while(cpos[cIdx][tmp+1] != n+1) {
	if(!occupied[cpos[cIdx][tmp+1]])
	    break;
	else
	    tmp = cpos[cIdx][tmp+1];
      }
      if(cpos[cIdx][tmp+1] == n+1)
	cout << "NO" << endl;
      else {
	tmp = cpos[cIdx][tmp+1];
	S[num-1].push(tmp);
	tmpPos[num-1] = tmp;
	occupied[tmp] = true;
	cout << "YES" << endl;
      }
    } else {
      if(S[num-1].size() > 0) {
	int tmp = S[num-1].top();
	c = WoU[tmp];
	int cIdx = (int)(c-'a');
	occupied[cpos[cIdx][tmp+1]] = false;
	cout << "YES" << endl;
	S[num-1].pop();
      } else {
	cout << "NO" << endl;
      }
    }
  }
  return 0;
}
