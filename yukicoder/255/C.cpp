#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> G(n);
  vector<vector<int>> from(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b; a--; b--;
    G[a].push_back(b);
    from[b].push_back(a);
  }
  int root = 0;
  rep(i, n) if(from[i].size() == 0) root = i;
  ll ans = 0;
  ll tmp = 0;
  auto dfs = [&](auto dfs, int cur, int par, ll depth) -> void {
    ll in = tmp;
    tmp++;
    for(int ne: G[cur]) dfs(dfs, ne, cur, depth+1);
    ll out = tmp;
    (ans += (out-in) * depth) %= mod;
  };
  dfs(dfs, root, -1, 0);
  cout << ans << "\n";
  return 0;
}
