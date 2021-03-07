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
  int n, K; cin >> n >> K;
  vector<vector<int>> A(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];
  UnionFind uf1(n), uf2(n);
  rep(i, n) {
    REP(j, i+1, n) {
      bool ok = true;
      rep(k, n) {
        if(A[k][i] + A[k][j] > K) ok = false;
      }
      if(ok) uf1.unite(i, j);
    }
  }
  rep(i, n) {
    REP(j, i+1, n) {
      bool ok = true;
      rep(k, n) {
        if(A[i][k] + A[j][k] > K) ok = false;
      }
      if(ok) uf2.unite(i, j);
    }
  }
  set<int> st1, st2;
  rep(i, n) st1.insert(uf1.root(i));
  rep(i, n) st2.insert(uf2.root(i));
  vector<ll> fact(55);
  fact[0] = 1;
  rep(i, 55) {
    if(i) fact[i] = fact[i-1] * i % mod2;
  }
  ll mul1 = 1, mul2 = 1;
  for(int i: st1) (mul1 *= fact[uf1.nGroup[i]]) %= mod2;
  for(int i: st2) (mul2 *= fact[uf2.nGroup[i]]) %= mod2;
  // cout << fact << endk;
  // cout << mul1 << ' ' << mul2 << endk;
  cout << mul1 * mul2 % mod2 << endk;
  return 0;
}
