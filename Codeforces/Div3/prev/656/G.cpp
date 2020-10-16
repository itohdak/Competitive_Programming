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
  vector<int> A(n), B(n);
  vector<vector<int>> cnt(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
    cnt[A[i]].push_back(i);
  }
  rep(i, n) {
    cin >> B[i];
    B[i]--;
    cnt[B[i]].push_back(i);
  }
  rep(i, n) if(cnt[i].size() != 2) {
    cout << -1 << "\n";
    return;
  }
  vector<int> ans;
  vector<bool> done(n);
  vector<int> path;
  set<int> tmp;
  auto dfs = [&](auto dfs, int cur, int pos) -> void {
    // cout << cur << ' ' << pos << endl;
    if(done[pos]) {
      if(tmp.size() > path.size()-tmp.size()) {
        for(int p: path) if(!tmp.count(p)) ans.push_back(p);
      } else {
        for(int a: tmp) ans.push_back(a);
      }
      return;
    }
    done[pos] = true;
    if(B[pos] == cur) tmp.insert(pos);
    path.push_back(pos);
    int val = A[pos] + B[pos] - cur;
    // int val = A[pos] + B[pos] - cur;
    int ne = cnt[val][0] + cnt[val][1] - pos;
    dfs(dfs, val, ne);
  };
  rep(i, n) {
    path.clear();
    tmp.clear();
    if(done[i]) continue;
    else {
      dfs(dfs, A[i], i);
    }
  }
  cout << ans.size() << "\n";
  for(int a: ans) cout << a+1 << ' ';
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
