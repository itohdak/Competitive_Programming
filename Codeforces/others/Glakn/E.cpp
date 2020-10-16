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

#define MAX_N 200050

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

struct edge {
  int u;
  int v;
  ll cost;
  edge(int _u, int _v, ll _cost) : u(_u), v(_v), cost(_cost) {}
};

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

vector<pair<int, int>> conn;
ll kruskal(int N, vector<edge>& es) {
  sort(es.begin(), es.end(), comp);
  UnionFind uf(N);
  ll res = 0;
  rep(i, es.size()) {
    edge e = es[i];
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
      conn.push_back(make_pair(e.u, e.v));
    }
  }
  return res;
}

void solve() {
  int m, n; cin >> m >> n;
  vector<ll> A(m); rep(i, m) cin >> A[i];
  vector<ll> B(n); rep(i, n) cin >> B[i];
  vector<edge> edges;
  ll sum = 0;
  rep(i, m) {
    int sz; cin >> sz;
    rep(j, sz) {
      int k; cin >> k;
      k--;
      edges.push_back({i, m+k, -(A[i]+B[k])});
      sum += A[i]+B[k];
    }
  }
  auto res = kruskal(n+m, edges);
  cout << sum + res << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
