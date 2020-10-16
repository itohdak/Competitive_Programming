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

#define MAX_N 500005

class UnionFind
{
public:
  int par[MAX_N];
  int depth[MAX_N];
  int nGroup[MAX_N];

  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }

  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;

    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};
void solve() {
  int n, m; cin >> n >> m;
  UnionFind uf(n*2);
  vector<pair<int, int>> P;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    P.push_back({u, v});
    G[u].push_back(v);
    G[v].push_back(u);
    uf.unite(u, v+n);
    uf.unite(u+n, v);
  }
  rep(i, n) {
    if(uf.same(i, i+n)) {
      cout << "NO" << endk;
      return;
    }
  }
  cout << "YES" << endk;
  vector<int> col(n, -1);
  auto bfs = [&](int i) {
    queue<pair<int, int>> q;
    q.push({i, 0});
    while(!q.empty()) {
      auto cur = q.front(); q.pop();
      auto [i, c] = cur;
      if(col[cur.first] != -1) continue;
      col[i] = c;
      for(int ne: G[i]) {
        if(col[ne] != -1) continue;
        q.push({ne, 1-col[i]});
      }
    }
  };
  rep(i, n) if(col[i] == -1) bfs(i);
  rep(i, m) cout << col[P[i].first];
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
