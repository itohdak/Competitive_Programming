#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<pair<int, int>>> G(n);
  rep(i, m) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    G[u].push_back({w, v});
  }
  vector<vector<int>> out(k+1);
  rep(i, n) {
    sort(all(G[i]));
    out[G[i].size()].push_back(i);
  }
  vector<vector<bitset<200005>>> memo(k+1, vector<bitset<200005>>(k, bitset<200005>()));
  REP(i, 1, k+1) { // out-degree
    rep(j, i) { // which edge to select
      for(int from: out[i]) {
        memo[i][j].set(G[from][j].second, 1);
      }
    }
  }
  ll ans = 0;
  auto dfs =
    [&](auto dfs, int deg, bitset<200005> bit) {
      if(deg == k+1) {
        if(bit.count() == n) ans++;
        return;
      }
      rep(i, deg) {
        dfs(dfs, deg+1, bit|memo[deg][i]);
      }
    };
  dfs(dfs, 1, bitset<200005>());
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
