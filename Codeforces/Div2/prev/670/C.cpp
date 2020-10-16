#include <bits/stdc++.h>
#include <print.hpp>
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
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if(n % 2) {
    cout << 1 << ' ' << G[0][0]+1 << endk;
    cout << 1 << ' ' << G[0][0]+1 << endk;
    return;
  }
  vector<int> child_num(n);
  vector<int> parent(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    parent[cur] = par;
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
        child_num[cur] += (child_num[ne]+1);
      }
    }
  };
  // int s = -1;
  // rep(i, n) if(G[i].size() == 1) s = i;
  // assert(s != -1);
  dfs(dfs, 0, -1);
  // cout << child_num << endl;
  rep(i, n) {
    if(child_num[i] == n/2-1) {
      int child = (G[i][0] == parent[i] ? G[i][1] : G[i][0]);
      cout << child+1 << ' ' << i+1 << endk;
      cout << child+1 << ' ' << parent[i]+1 << endk;
      return;
    }
  }
  cout << 1 << ' ' << G[0][0]+1 << endk;
  cout << 1 << ' ' << G[0][0]+1 << endk;
  return;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
