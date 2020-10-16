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
  int n; cin >> n;
  string s; cin >> s;
  int ans = inf;
  auto dfs = [&](auto dfs, string s, char c, int cnt) {
    if(c > 'z') return;
    if(s.size() == 1) {
      cnt += (s[0] != c);
      ans = min(cnt, ans);
      return;
    }
    int cur = 0;
    rep(i, s.size()/2) cur += (s[i] != c);
    dfs(dfs, s.substr(s.size()/2), c+1, cnt+cur);
    cur = 0;
    REP(i, s.size()/2, s.size()) cur += (s[i] != c);
    dfs(dfs, s.substr(0, s.size()/2), c+1, cnt+cur);
  };
  dfs(dfs, s, 'a', 0);
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
