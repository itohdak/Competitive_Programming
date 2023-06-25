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

#define MAX_N 60

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
  ld cost;
  edge(int _u, int _v, ld _cost) : u(_u), v(_v), cost(_cost) {}
};

vector<tuple<int, int, ld>> conn;
ld kruskal(int N, vector<edge>& es) {
  sort(es.begin(), es.end(), [&](const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
  });
  UnionFind uf(N);
  ld res = 0;
  rep(i, es.size()) {
    edge e = es[i];
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
      conn.push_back(make_tuple(e.u, e.v, e.cost));
    }
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> Px(n), Py(n);
  rep(i, n) cin >> Px[i] >> Py[i];
  vector<ll> Cx(m), Cy(m), R(m);
  rep(i, m) cin >> Cx[i] >> Cy[i] >> R[i];
  ld ans = longinf;
  rep(k, 1<<m) {
    vector<edge> E;
    rep(i, m) {
      if(!((k>>i)&1)) continue;
      auto dist2 = [&](int i, int j) {
        return (Cx[i]-Cx[j])*(Cx[i]-Cx[j])+(Cy[i]-Cy[j])*(Cy[i]-Cy[j]);
      };
      rep(j, i) {
        if(!((k>>j)&1)) continue;
        ll d2 = dist2(i, j);
        ld d = sqrt((ld)d2);
        if(d2 < (R[i]-R[j])*(R[i]-R[j])) {
          E.push_back({i, j, abs(R[i]-R[j])-d});
        } else if(d2 <= (R[i]+R[j])*(R[i]+R[j])) {
          E.push_back({i, j, 0});
        } else {
          E.push_back({i, j, d-(R[i]+R[j])});
        }
      }
    }
    rep(i, n) {
      auto dist = [&](int i, int j) {
        if((Px[i]-Cx[j])*(Px[i]-Cx[j])+(Py[i]-Cy[j])*(Py[i]-Cy[j]) == R[j]*R[j]) return (ld)0;
        else return abs(sqrt((ld)((Px[i]-Cx[j])*(Px[i]-Cx[j])+(Py[i]-Cy[j])*(Py[i]-Cy[j])))-R[j]);
      };
      auto dist2 = [&](int i, int j) {
        return sqrt((Px[i]-Px[j])*(Px[i]-Px[j])+(Py[i]-Py[j])*(Py[i]-Py[j]));
      };
      rep(j, m) {
        if(!((k>>j)&1)) continue;
        E.push_back({m+i, j, dist(i, j)});
      }
      rep(j, i) {
        E.push_back({m+i, m+j, dist2(i, j)});
      }
    }
    auto tmp = kruskal(n+m, E);
    chmin(ans, tmp);
  }
  cout << fixed << setprecision(10) << ans << endk;
  return 0;
}
