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

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< edge< T > > eulerian_path(Edges< T > es, int s, bool directed) {
  int V = 0;
  for(auto &e : es) V = max(V, max(e.to, e.src) + 1);
  vector< vector< pair< edge< T >, int > > > g(V);
  for(auto &e : es) {
    int sz_to = (int) g[e.to].size();
    g[e.src].emplace_back(e, sz_to);
    if(!directed) {
      int sz_src = (int) g[e.src].size() - 1;
      swap(e.src, e.to);
      g[e.src].emplace_back(e, sz_src);
    }
  }
  vector< edge< T > > ord;
  stack< pair< int, edge< T > > > st;
  st.emplace(s, edge< T >(-1, -1));
  while(st.size()) {
    int idx = st.top().first;
    if(g[idx].empty()) {
      ord.emplace_back(st.top().second);
      st.pop();
    } else {
      auto e = g[idx].back();
      g[idx].pop_back();
      if(e.second == -1) continue;
      if(!directed) g[e.first.to][e.second].second = -1;
      st.emplace(e.first.to, e.first);
    }
  }
  ord.pop_back();
  reverse(begin(ord), end(ord));
  if(ord.size() != es.size()) return {};
  return ord;
}
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
  int n; cin >> n;
  vector<ll> B(n-1), C(n-1);
  vector<ll> V;
  rep(i, n-1) {
    cin >> B[i];
    V.push_back(B[i]);
  }
  rep(i, n-1) {
    cin >> C[i];
    V.push_back(C[i]);
  }
  sort(all(V));
  V.erase(unique(all(V)), end(V));
  Edges<int> es;
  vector<int> cnt(V.size()), cnt_self(V.size());
  UnionFind uf(V.size());
  rep(i, n-1) {
    if(B[i] > C[i]) {
      cout << -1 << endk;
      return 0;
    }
    int idb = lower_bound(all(V), B[i])-begin(V);
    int idc = lower_bound(all(V), C[i])-begin(V);
    uf.unite(idb, idc);
    if(idb == idc) {
      cnt_self[idb]++;
    } else {
      es.push_back({idb, idc, 1});
      cnt[idb]++;
      cnt[idc]++;
    }
  }
  if(uf.nGroup[uf.root(0)] != V.size()) { // not connected
    cout << -1 << endk;
    return 0;
  }
  if(es.empty()) {
    rep(i, V.size()) {
      if(cnt_self[i]) {
        cout << V[i];
        rep(j, cnt_self[i]) {
          cout << ' ' << V[i];
        }
        cout << endk;
      }
    }
  } else {
    vector<int> odd;
    rep(i, V.size()) if(cnt[i]&1) odd.push_back(i);
    if(odd.size() == 0 || odd.size() == 2) {
      int i = (odd.empty() ? 0 : odd[0]);
      auto ret = eulerian_path(es, i, false);
      assert(ret.size());
      cout << V[i];
      while(cnt_self[i]) {
        cout << ' ' << V[i];
        cnt_self[i]--;
      }
      for(auto v: ret) {
        cout << ' ' << V[v];
        while(cnt_self[v]) {
          cout << ' ' << V[v];
          cnt_self[v]--;
        }
      }
      cout << endk;
    } else {
      cout << -1 << endk;
    }
  }
  return 0;
}
