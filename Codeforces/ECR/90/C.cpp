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
  string s;
  cin >> s;
  int n = s.size();
  map<int, int> id;
  int cur = 0;
  rep(i, n) {
    cur += (s[i]=='+' ? 1 : -1);
    if(!id.count(cur)) id[cur] = i+1;
  }
  ll ans = 0;
  int i = 0;
  // cout << id << endl;
  while(true) {
    if(!id.count(i-1)) {
      ans += n;
      break;
    }
    ans += id[i-1];
    i--;
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
