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
  int N; cin >> N;
  vector<vector<int>> G(N);
  rep(i, N-1) {
    int v, w; cin >> v >> w; v--; w--;
    G[v].push_back(w);
    G[w].push_back(v);
  }
  vector<ll> nChild(N);
  vector<ll> ans(N);
  ll tmp = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    tmp++;
    ll in = tmp;
    ll same = 0;
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
        same += nChild[ne] * nChild[ne];
      }
    }
    ll out = tmp;
    nChild[cur] = out-in+1;
    ans[cur] = nChild[cur] * nChild[cur] - same;
  };
  dfs(dfs, 0, -1);
  rep(i, N) cout << ans[i] << "\n";
  return 0;
}
