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

#define MAX_N 600005

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
  int n, q; cin >> n >> q;
  UnionFind uf(n+q);
  vector<int> B(n);
  map<int, int> mp;
  iota(all(B), 0);
  rep(i, n) mp[i] = i;
  int nx = n;
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      x--; y--;
      if(B[y] >= 0) {
        if(B[x] >= 0) uf.unite(B[x], B[y]);
        mp.erase(B[x]);
        mp.erase(B[y]);
        B[x] = uf.root(B[y]);
        B[y] = -1;
        mp[B[x]] = x;
      }
    } else if(t == 2) {
      int x; cin >> x;
      x--;
      if(B[x] == -1) {
        B[x] = nx;
        mp[B[x]] = x;
      } else {
        uf.unite(B[x], nx);
        mp.erase(B[x]);
        B[x] = uf.root(nx);
        mp[uf.root(nx)] = x;
      }
      nx++;
    } else {
      int x; cin >> x;
      x--;
      cout << mp[uf.root(x)]+1 << endk;
    }
  }
  return 0;
}
