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

#define MAX_N 300005

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
      if(depth[x] == depth[y]) {
        depth[x]++;
      }
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  vector<vector<pair<int, ll>>> G(n);
  UnionFind uf(n);
  rep(i, m) {
    int a, b; ll c; cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, c});
    G[b].push_back({a, -c});
    uf.unite(a, b);
  }
  vector<bool> vis(n);
  vector<ll> level(n);
  set<int> loop;
  auto dfs = [&](auto dfs, int cur) -> void {
    vis[cur] = true;
    for(auto [ne, c]: G[cur]) {
      if(vis[ne] && level[ne] != level[cur] + c) {
        loop.insert(uf.root(cur));
        return;
      }
      if(!vis[ne]) {
        level[ne] = level[cur] + c;
        dfs(dfs, ne);
        if(loop.count(uf.root(cur))) return;
      }
    }
  };
  rep(i, n) {
    if(!vis[i]) {
      level[i] = 0;
      dfs(dfs, i);
    }
  }
  rep(i, q) {
    int x, y; cin >> x >> y;
    x--; y--;
    if(!uf.same(x, y)) {
      cout << "nan" << endk;
    } else if(loop.count(uf.root(x))) {
      cout << "inf" << endk;
    } else {
      cout << level[y] - level[x] << endk;
    }
  }
  return 0;
}
