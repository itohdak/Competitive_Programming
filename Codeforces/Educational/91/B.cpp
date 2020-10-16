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
  map<char, char> mp = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
  string s; cin >> s;
  map<char, int> cnt;
  for(char c: s) cnt[c]++;
  int mx = -1;
  char mxc;
  for(auto ele: cnt) {
    if(ele.second > mx) {
      mx = ele.second;
      mxc = ele.first;
    }
  }
  cout << string(s.size(), mp[mxc]) << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
