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
  int n, k; cin >> n >> k;
  vector<set<int>> G(n);
  rep(i, n-1) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    G[x].insert(y);
    G[y].insert(x);
  }
  if(k==1) {
    cout << n-1 << "\n";
    return;
  }
  vector<set<int>> leaves(n);
  priority_queue<pair<int, int>> q;
  rep(i, n) if(G[i].size() == 1) leaves[*G[i].begin()].insert(i);
  rep(i, n) if(G[i].size() != 1) q.emplace(leaves[i].size(), i);
  int ans = 0;
  while(!q.empty()) {
    auto ele = q.top(); q.pop();
    int c = ele.first;
    int cur = ele.second;
    if(c != (int)leaves[cur].size()) continue;
    if((int)leaves[cur].size() < k) break;
    ans++;
    rep(i, k) {
      int leaf = *leaves[cur].begin();
      G[cur].erase(leaf);
      G[leaf].erase(cur);
      leaves[cur].erase(leaf);
    }
    if(G[cur].size() == 1) {
      int to = *G[cur].begin();
      leaves[to].insert(cur);
      q.emplace(leaves[to].size(), to);
    } else {
      q.emplace(leaves[cur].size(), cur);
    }
  }
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
