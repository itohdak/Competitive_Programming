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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> H(n); rep(i, n) cin >> H[i];
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int q; cin >> q;
  vector<int> A(q), B(q), E(q);
  rep(i, q) {
    cin >> A[i] >> B[i] >> E[i];
    A[i]--; B[i]--;
  }
  vector<int> id(q);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return H[A[i]]+E[i] < H[A[j]]+E[j];
  });
  vector<int> id2(n);
  iota(all(id2), 0);
  sort(all(id2), [&](int i, int j) {
    return H[i] < H[j];
  });
  // cout << id << endk;
  // cout << id2 << endk;
  int tmp = 0;
  UnionFind uf(n);
  vector<bool> ans(q);
  for(int i: id) {
    // cout << i << endk;
    int a = A[i], b = B[i];
    ll e = E[i];
    while(tmp < n && H[id2[tmp]] <= H[a]+e) {
      int cur = id2[tmp];
      // cout << "==== " << cur << endk;
      for(int ne: G[cur]) {
	if(H[ne] <= H[cur]) {
	  uf.unite(ne, cur);
	}
      }
      tmp++;
    }
    ans[i] = uf.same(a, b);
  }
  rep(i, q) {
    cout << (ans[i] ? "YES" : "NO") << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
