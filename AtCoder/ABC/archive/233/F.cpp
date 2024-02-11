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

#define MAX_N 300005

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
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> dist;
vector<int> par;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  par.assign(n, -1);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({dist[ne], ne});
        par[ne] = cur;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  int m; cin >> m;
  UnionFind uf(n);
  vector<vector<edge>> G(n);
  map<pair<int, int>, int> id;
  vector<int> A(m), B(m);
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    uf.unite(A[i], B[i]);
    G[A[i]].push_back({B[i], 1});
    G[B[i]].push_back({A[i], 1});
    id[{A[i], B[i]}] = i;
    id[{B[i], A[i]}] = i;
  }
  map<int, vector<int>> mp;
  rep(i, n) {
    mp[uf.root(i)].push_back(i);
  }
  vector<int> Q(n);
  for(auto [_, v]: mp) {
    vector<int> tmp = v;
    sort(all(v), [&](int i, int j) {
      return P[i] < P[j];
    });
    rep(i, v.size()) Q[tmp[i]] = P[v[i]];
  }
  rep(i, n) {
    if(Q[i] != i) {
      cout << -1 << endk;
      return 0;
    }
  }

  vector<int> pos(n);
  rep(i, n) pos[P[i]] = i;
  vector<int> ans;
  rep(i, n) {
    dijkstra(n, G, i);
    int t = pos[i];
    assert(dist[t] != longinf);
    vector<int> path;
    int tmp = t;
    while(tmp != i) {
      assert(id.count({tmp, par[tmp]}));
      path.push_back(id[{tmp, par[tmp]}]);
      tmp = par[tmp];
    }
    if(path.size()) {
      for(auto i: path) ans.push_back(i);
      path.pop_back();
      reverse(all(path));
      for(auto i: path) ans.push_back(i);
      swap(pos[i], pos[P[i]]);
      swap(P[i], P[t]);
    }
  }
  cout << ans.size() << endk;
  for(int a: ans) cout << a+1 << ' ';
  cout << endk;
  // cout << P << endk;
  return 0;
}
