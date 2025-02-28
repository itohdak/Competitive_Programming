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
  int n; cin >> n;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  int m; cin >> m;
  UnionFind uf(n);
  vector<vector<int>> G(n);
  vector<int> A(m), B(m);
  map<pair<int, int>, int> id;
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    id[{A[i], B[i]}] = id[{B[i], A[i]}] = i;
    if(uf.same(A[i], B[i])) continue;
    uf.unite(A[i], B[i]);
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  map<int, vector<int>> mp;
  rep(i, n) mp[uf.root(i)].push_back(i);
  for(auto [_, v]: mp) {
    vector<int> u;
    for(int i: v) u.push_back(P[i]);
    sort(all(u));
    rep(i, v.size()) {
      if(v[i] != u[i]) {
        cout << -1 << endk;
        return 0;
      }
    }
  }
  vector<int> ans;
  vector<int> sz(n);
  rep(i, n) sz[i] = G[i].size();
  for(auto [_, v]: mp) {
    bool found = false;
    vector<int> path;
    auto dfs = [&](auto dfs, int cur, int par, int t) -> void {
      if(P[cur] == t) {
        found = true;
        return;
      }
      for(int ne: G[cur]) {
        if(ne == par) continue;
        path.push_back(id[{cur, ne}]);
        dfs(dfs, ne, cur, t);
        if(found) return;
        path.pop_back();
      }
    };
    queue<int> q;
    for(int i: v) if(sz[i] == 1) q.push(i);
    while(q.size()) {
      auto cur = q.front(); q.pop();
      found = false;
      path.clear();
      dfs(dfs, cur, -1, cur);
      assert(found);
      reverse(all(path));
      for(auto p: path) {
        ans.push_back(p);
        swap(P[A[p]], P[B[p]]);
      }
      for(int ne: G[cur]) {
        sz[ne]--;
        if(sz[ne] == 1) q.push(ne);
      }
    }
  }
  cout << ans.size() << endk;
  for(auto a: ans) cout << a+1 << ' ';
  cout << endk;
  return 0;
}
