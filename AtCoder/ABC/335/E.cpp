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
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<pair<int, int>> E(m);
  UnionFind uf(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    E[i] = {u, v};
    if(A[u] == A[v]) {
      uf.unite(u, v);
    }
  }
  map<int, vector<int>> mp;
  rep(i, n) mp[uf.root(i)].push_back(i);
  vector<int> rt(n);
  for(auto& [_, v]: mp) {
    sort(all(v));
    for(int i: v) {
      rt[i] = v[0];
    }
  }
  vector<vector<int>> G(n);
  rep(i, m) {
    auto [u, v] = E[i];
    if(!uf.same(u, v)) {
      int ru = rt[u];
      int rv = rt[v];
      if(A[ru] > A[rv]) {
        G[rv].push_back(ru);
      }
      if(A[ru] < A[rv]) {
        G[ru].push_back(rv);
      }
      assert(A[ru] != A[rv]);
    }
  }
  vector<int> id;
  rep(i, n) {
    id.push_back(rt[i]);
  }
  sort(all(id));
  id.erase(unique(all(id)), end(id));
  sort(all(id), [&](int i, int j) {
    if(A[i] == A[j]) return i < j;
    return A[i] < A[j];
  });
  assert(rt[0] == 0);
  vector<int> score(n, -inf);
  score[rt[0]] = 1;
  for(int i: id) {
    for(int ne: G[i]) {
      chmax(score[ne], score[i] + 1);
    }
  }
  cout << max(score[rt[n-1]], 0) << endk;
  return 0;
}
