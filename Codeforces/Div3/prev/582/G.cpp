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
void solve() {
  int n, m; cin >> n >> m;
  set<tuple<int, int, int>> st;
  rep(i, n-1) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    st.insert({w, u, v});
  }
  vector<int> Q(m), id(m);
  rep(i, m) {
    cin >> Q[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return Q[i] < Q[j];
  });
  UnionFind uf(n);
  auto itr = st.begin();
  vector<ll> ans(m);
  ll cnt = 0;
  for(int i: id) {
    while(itr != st.end() && get<0>(*itr) <= Q[i]) {
      auto [w, u, v] = *itr;
      int nu = uf.nGroup[uf.root(u)];
      int nv = uf.nGroup[uf.root(v)];
      cnt -= 1LL*nu*(nu-1)/2 + 1LL*nv*(nv-1)/2;
      cnt += 1LL*(nu+nv)*(nu+nv-1)/2;
      uf.unite(u, v);
      itr++;
    }
    ans[i] = cnt;
  }
  rep(i, m) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
