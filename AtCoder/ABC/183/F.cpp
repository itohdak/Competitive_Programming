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
  vector<map<int, int>> nClass;

  UnionFind(int n, vector<int>& _class) {
    init(n, _class);
  }

  void init(int n, vector<int>& _class) {
    nClass = vector<map<int, int>>(n);
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
      nClass[i][_class[i]] += 1;
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
      for(auto ele: nClass[x]) {
        nClass[y][ele.first] += ele.second;
      }
      nGroup[x] = 0;
      nClass[x].clear();
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      for(auto ele: nClass[y]) {
        nClass[x][ele.first] += ele.second;
      }
      nGroup[y] = 0;
      nClass[y].clear();
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> C(n);
  rep(i, n) {
    cin >> C[i];
    C[i]--;
  }
  UnionFind uf(n, C);
  // cout << uf.nClass << endk;
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int a, b; cin >> a >> b;
      a--; b--;
      uf.unite(a, b);
    } else {
      int x, y; cin >> x >> y;
      x--; y--;
      if(!uf.nClass[uf.root(x)].count(y)) cout << 0 << endk;
      else cout << uf.nClass[uf.root(x)][y] << endk;
    }
    // cout << uf.nClass << endk;
  }
  return 0;
}
