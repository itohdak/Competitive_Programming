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
  int nPower[MAX_N];
  bool powered[MAX_N];

  UnionFind(int n, int m) {
    init(n, m);
  }

  void init(int n, int m) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
      nPower[i] = (i >= m);
      powered[i] = (i >= m);
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
      nPower[y] += nPower[x];
      powered[y] = powered[x] || powered[y];
      nGroup[x] = 0;
      nPower[x] = 0;
      powered[x] = false;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nPower[x] += nPower[y];
      powered[x] = powered[x] || powered[y];
      nGroup[y] = 0;
      nPower[y] = 0;
      powered[y] = false;
      if(depth[x] == depth[y]) {
        depth[x]++;
      }
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, e; cin >> n >> m >> e;
  vector<pair<int, int>> E(e);
  for(auto& [u, v]: E) {
    cin >> u >> v;
    u--; v--;
  }
  vector<bool> avail(e, true);
  int q; cin >> q;
  vector<int> X(q);
  rep(i, q) {
    cin >> X[i];
    X[i]--;
    avail[X[i]] = false;
  }
  UnionFind uf(n+m, n);
  vector<int> ans(q);
  int tmp = 0;
  auto merge = [&](int u, int v) {
    if(!uf.same(u, v)) {
      bool p1 = uf.powered[uf.root(u)];
      bool p2 = uf.powered[uf.root(v)];
      if(p1 && p2) {
      } else if(p1) {
        tmp += uf.nGroup[uf.root(v)] - uf.nPower[uf.root(v)];
      } else if(p2) {
        tmp += uf.nGroup[uf.root(u)] - uf.nPower[uf.root(u)];
      }
      uf.unite(u, v);
    }
  };
  rep(i, e) {
    if(avail[i]) {
      auto [u, v] = E[i];
      merge(u, v);
    }
  }
  rrep(i, q) {
    ans[i] = tmp;
    auto [u, v] = E[X[i]];
    merge(u, v);
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
