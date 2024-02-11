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
  int n, m, q; cin >> n >> m >> q;
  UnionFind uf(n);
  vector<int> A(m), B(m), C(m);
  rep(i, m) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--;
  }
  vector<int> U(q), V(q), W(q);
  rep(i, q) {
    cin >> U[i] >> V[i] >> W[i];
    U[i]--; V[i]--;
  }
  vector<int> id(m);
  iota(all(id), 0);
  vector<int> id2(q);
  iota(all(id2), 0);
  sort(all(id), [&](int i, int j) {
    return C[i] < C[j];
  });
  sort(all(id2), [&](int i, int j) {
    return W[i] < W[j];
  });
  vector<string> ans(q);
  int i = 0;
  int l = 0;
  while(l < q) {
    int r = l;
    while(i < m && W[id2[l]] > C[id[i]]) {
      uf.unite(A[id[i]], B[id[i]]);
      i++;
    }
    while(r < q && W[id2[r]] == W[id2[l]]) {
      ans[id2[r]] = (!uf.same(U[id2[r]], V[id2[r]]) ? "Yes" : "No");
      r++;
    }
    l = r;
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
