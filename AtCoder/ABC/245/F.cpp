#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  UnionFind uf(n);
  vector<vector<int>> E(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    uf.unite(u, v);
  }
  map<int, vector<int>> mp;
  rep(i, n) mp[uf.root(i)].push_back(i);
  int ans = 0;
  for(auto [_, v]: mp) {
    scc_graph G(v.size());
    map<int, int> id;
    map<int, int> id_rev;
    rep(i, v.size()) {
      id[v[i]] = i;
      id_rev[i] = v[i];
    }
    for(auto i: v) {
      int from = id[i];
      for(auto j: E[i]) {
        assert(id.count(j));
        int to = id[j];
        G.add_edge(from, to);
      }
    }
    auto ret = G.scc();
    int sz = ret.size();
    vector<vector<int>> G2(sz);
    map<int, int> id2;
    rep(i, sz) {
      for(int j: ret[i]) {
        assert(id_rev.count(j));
        id2[id_rev[j]] = i;
      }
    }
    for(auto i: v) {
      int from = id2[i];
      for(auto j: E[i]) {
        assert(id2.count(j));
        int to = id2[j];
        if(from == to) continue;
        G2[to].push_back(from);
      }
    }
    vector<bool> ok(sz);
    rrep(i, sz) {
      if(ret[i].size() > 1) {
        ok[i] = true;
      }
      if(ok[i]) {
        for(int ne: G2[i]) {
          ok[ne] = true;
        }
      }
    }
    rep(i, sz) if(ok[i]) ans += ret[i].size();
  }
  cout << ans << endk;
  return 0;
}
