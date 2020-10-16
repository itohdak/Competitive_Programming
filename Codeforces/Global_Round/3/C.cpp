#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void swap(vector<int>& P, vector<int>& pos, int i, int j) {
  pos[P[i]] = j;
  pos[P[j]] = i;

  int tmp = P[i];
  P[i] = P[j];
  P[j] = tmp;
}

int main() {
  int n;
  cin >> n;
  vector<int> P(n), pos(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    pos[P[i]] = i;
  }
  vector<pair<int, int> > ans;
  rep(i, n) {
    if(i != pos[i]) {
      if(abs(pos[i] - i) >= n / 2) {
	ans.push_back(make_pair(i, pos[i]));
      } else {
	if(i < n/2 && pos[i] < n/2) {
	  ans.push_back(make_pair(pos[i], pos[i]+n/2));
	  ans.push_back(make_pair(i, pos[i]+n/2));
	  ans.push_back(make_pair(pos[i], pos[i]+n/2));
	} else if(i < n/2 && pos[i] >= n/2) {
	  ans.push_back(make_pair(i, i+n/2));
	  ans.push_back(make_pair(pos[i]-n/2, pos[i]));
	  ans.push_back(make_pair(pos[i]-n/2, i+n/2));
	  ans.push_back(make_pair(pos[i]-n/2, pos[i]));
	  ans.push_back(make_pair(i, i+n/2));
	} else {
	  ans.push_back(make_pair(i-n/2, i));
	  ans.push_back(make_pair(i-n/2, pos[i]));
	  ans.push_back(make_pair(i-n/2, i));
	}
      }
      swap(P, pos, i, pos[i]);
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    pair<int, int> tmp = ans[i];
    cout << tmp.first+1 << ' ' << tmp.second+1 << endl;
  }
  return 0;
}

