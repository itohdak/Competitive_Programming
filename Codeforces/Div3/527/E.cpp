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

#define MAX_N 200005

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
  vector<vector<int>> G(n);
  UnionFind uf(n);
  rep(i, m) {
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
    uf.unite(x, y);
  }
  map<int, set<int>> mp;
  rep(i, n) mp[uf.root(i)].insert(i);
  vector<int> D;
  vector<int> in, out;
  int id = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    D[cur] = (par==-1 ? 0 : D[par]+1);
    in[cur] = id++;
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
    }
    out[cur] = id++;
  };
  vector<pair<int, int>> v;
  int mx = 0;
  for(auto ele: mp) {
    D = vector<int>(n);
    in = vector<int>(n);
    out = vector<int>(n);
    id = 0;
    dfs(dfs, *ele.second.begin(), -1);
    int mxi = -1;
    int mxd = -1;
    rep(i, n) if(D[i] > mxd && ele.second.count(i)) {
      mxi = i;
      mxd = D[i];
    }
    assert(mxi != -1);
    D = vector<int>(n);
    in = vector<int>(n);
    out = vector<int>(n);
    id = 0;
    dfs(dfs, mxi, -1);
    mxi = -1;
    mxd = -1;
    rep(i, n) if(D[i] > mxd && ele.second.count(i)) {
      mxi = i;
      mxd = D[i];
    }
    assert(mxi != -1);
    int mid = -1;
    rep(i, n) if(D[i] == mxd/2 && in[i] <= in[mxi] && out[mxi] <= out[i] && ele.second.count(i)) mid = i;
    assert(mid != -1);
    v.push_back({mxd-mxd/2, mid});
    chmax(mx, mxd);
  }
  sort(all(v));
  reverse(all(v));
  // cout << v << endk;
  if(v.size() == 1) {
  } else if(v.size() <= 2) {
    chmax(mx, v[0].first+v[1].first+1);
  } else if(v[0].first == v[2].first) {
    chmax(mx, v[0].first+v[2].first+2);
  } else {
    chmax(mx, v[0].first+v[1].first+1);
  }
  cout << mx << endk;
  rep(i, v.size()) {
    if(i) cout << v[0].second+1 << ' ' << v[i].second+1 << endk;
  }
  return 0;
}
