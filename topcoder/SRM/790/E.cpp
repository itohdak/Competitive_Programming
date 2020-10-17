#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

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
ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
class TheSocialNetwork {
public:
  int minimumCut(int n, int m, vector<int> u, vector<int> v, vector<int> l) {
    rep(i, m) u[i]--, v[i]--;
    vector<int> id(m);
    rep(i, m) id[i] = i;
    sort(all(id), [&](int i, int j) {
      return l[i] > l[j];
    });
    ll ans = 0;
    UnionFind uf(n);
    int rem = n;
    rep(i, m) {
      if(uf.same(u[id[i]], v[id[i]])) continue;
      // cout << id[i] << endl;
      // cout << u[id[i]] << ' ' << v[id[i]] << endl;
      if(rem == 2) (ans += modpow(2, l[id[i]])) %= mod;
      else {
        uf.unite(u[id[i]], v[id[i]]);
        rem--;
      }
    }
    return ans;
  }
};

int main() {
  // int n = 8, m = 11;
  // vector<int> u = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 7};
  // vector<int> v = {2, 8, 3, 5, 4, 6, 7, 5, 6, 8, 8};
  // vector<int> l = {2, 3, 1, 6, 11, 8, 9, 10, 7, 4, 5};
  int n = 5, m = 7;
  vector<int> u = {1, 1, 1, 2, 2, 3, 3},
    v = {5, 3, 2, 5, 3, 5, 4},
    l = {1, 8, 2, 3, 4, 6, 9};
  cout << TheSocialNetwork().minimumCut(n, m, u, v, l) << endl;
}
