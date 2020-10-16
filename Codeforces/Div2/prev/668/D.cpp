#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  int a, b, da, db; cin >> a >> b >> da >> db;
  a--; b--;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> d(n);
  auto dfs = [&](auto dfs, int cur, int par, int depth) -> void {
    d[cur] = depth;
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur, depth+1);
    }
  };
  dfs(dfs, a, -1, 0);
  if(d[b] <= da) {
    cout << "Alice" << endk;
    return;
  }
  int j = max_element(all(d)) - begin(d);
  dfs(dfs, j, -1, 0);
  int dmx = *max_element(all(d));
  cout << (min(dmx, db) > 2*da ? "Bob" : "Alice") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
