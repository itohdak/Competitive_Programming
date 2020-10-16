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
  string a, b; cin >> a >> b;
  deque<char> q;
  rep(i, n) q.push_back(a[i]);
  vector<int> ans;
  rep(i, n) {
    if(i%2==0) {
      if(q.front()==b[n-1-i]) ans.push_back(1);
      ans.push_back(n-i);
      q.pop_front();
    } else {
      if(q.back()!=b[n-1-i]) ans.push_back(1);
      ans.push_back(n-i);
      q.pop_back();
    }
  }
  cout << ans.size() << ' ';
  for(int i: ans) cout << i << ' ';
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
