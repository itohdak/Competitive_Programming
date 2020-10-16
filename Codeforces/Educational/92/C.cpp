#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  string s; cin >> s;
  int n = s.size();
  map<char, vector<int>> mp;
  rep(i, n) mp[s[i]].push_back(i);
  int mx = 0;
  rep(i, 10) rep(j, 10) {
    char s1 = char('0'+i);
    char s2 = char('0'+j);
    int k = 0;
    int cnt = 0;
    int flag = 0;
    while(1) {
      vector<int>::iterator itr;
      if(flag==0) {
        itr = lower_bound(all(mp[s1]), k);
        if(itr == mp[s1].end()) break;
      } else {
        itr = lower_bound(all(mp[s2]), k);
        if(itr == mp[s2].end()) break;
      }
      cnt++;
      flag = 1-flag;
      k = *itr+1;
    }
    if(i==j) mx = max(cnt, mx);
    else mx = max(cnt/2*2, mx);
  }
  cout << n-mx << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
