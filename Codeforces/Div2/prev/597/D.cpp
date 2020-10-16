#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

#define MAX_N 100000

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

vector<edge> es;
vector<pair<int, int> > conn;
vector<int> build;
bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

ll kruskal(int N) {
  sort(es.begin(), es.end(), comp);
  UnionFind uf(N);
  ll res = 0;
  rep(i, es.size()) {
    edge e = es[i];
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
      if(e.u == N-1 || e.v == N-1) {
        build.push_back(min(e.u, e.v));
      } else {
        conn.push_back(make_pair(e.u, e.v));
      }
    }
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > XY(N);
  vector<ll> C(N), K(N);
  rep(i, N) cin >> XY[i].first >> XY[i].second;
  rep(i, N) cin >> C[i];
  rep(i, N) cin >> K[i];
  rep(i, N+1) REP(j, i+1, N+1) {
    if(j == N) {
      es.push_back(edge(i, j, C[i]));
    } else {
      ll c = (abs(XY[i].first - XY[j].first) + abs(XY[i].second - XY[j].second)) * (K[i] + K[j]);
      es.push_back(edge(i, j, c));
    }
  }
  cout << kruskal(N+1) << endl;
  cout << build.size() << endl;
  for(auto b: build) cout << b+1 << ' ';
  cout << endl;
  cout << conn.size() << endl;
  for(auto c: conn) cout << c.first+1 << ' ' << c.second+1 << endl;
  return 0;
}

