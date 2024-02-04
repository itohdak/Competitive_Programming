#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  // dfs
  {
    vector<int> T1(n, -1);
    auto dfs = [&](auto dfs, int cur, int par) -> void {
      for(int ne: G[cur]) {
        if(ne == par) continue;
        if(ne == 0) continue;
        if(T1[ne] != -1) continue;
        T1[ne] = cur;
        dfs(dfs, ne, cur);
      }
    };
    dfs(dfs, 0, -1);
    rep(i, n) {
      if(i == 0) continue;
      cout << i+1 << ' ' << T1[i]+1 << endk;
    }
  }

  // bfs
  {
    deque<int> q;
    q.push_back({0});
    vector<int> T2(n, -1);
    while(q.size()) {
      int cur = q.front(); q.pop_front();
      for(int ne: G[cur]) {
        if(ne == 0) continue;
        if(T2[ne] != -1) continue;
        T2[ne] = cur;
        q.push_back(ne);
      }
    }
    rep(i, n) {
      if(i == 0) continue;
      cout << i+1 << ' ' << T2[i]+1 << endk;
    }
  }

  return 0;
}
