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
int maxAccepted = 0;
map<ll, int> cntRejected;
ll kruskal(int N, vector<edge>& es) {
  sort(es.begin(), es.end(), comp);
  UnionFind uf(N);
  ll res = 0;
  ll prevCost = 0;
  set<pair<int, int>> st;
  rep(i, es.size()) {
    edge e = es[i];
    if(e.cost != prevCost) {
      st.clear();
      REP(j, i, es.size()) {
        if(es[j].cost != e.cost) break;
        if(uf.same(es[j].u, es[j].v)) st.insert({es[j].u, es[j].v});
      }
      prevCost = e.cost;
    }
    if(!uf.same(e.u, e.v)) {
      // cout << "accepted " << e.u+1 << ' ' << e.v+1 << ' ' << e.cost << endk;
      chmax(maxAccepted, e.cost);
      uf.unite(e.u, e.v);
      res += e.cost;
      conn.push_back(make_pair(e.u, e.v));
    } else {
      // cout << "rejected " << e.u+1 << ' ' << e.v+1 << ' ' << e.cost << endk;
      if(!st.count({e.u, e.v})) cntRejected[e.cost]++;
    }
  }
  return res;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<edge> E;
  rep(i, m) {
    int u, v; ll w; cin >> u >> v >> w;
    u--; v--;
    E.push_back({u, v, w});
    // E.push_back({v, u, w});
  }
  kruskal(n, E);
  int ans = 0;
  for(auto itr=cntRejected.begin(); itr!=cntRejected.end(); itr++) {
    if(itr->first > maxAccepted) break;
    ans += itr->second;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
