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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> D(n); rep(i, n) cin >> D[i];
  UnionFind uf(n);
  vector<vector<int>> G(n);
  bool ok = true;
  vector<int> cnt(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
    cnt[a]++;
    cnt[b]++;
    if(uf.same(a, b)) ok = false;
    uf.unite(a, b);
  }
  rep(i, n) {
    if(cnt[i] > D[i]) ok = false;
  }
  if(accumulate(all(D), 0LL) != (n-1)*2) ok = false;
  if(!ok) {
    cout << -1 << endk;
    return 0;
  }
  map<int, vector<int>> root;
  rep(i, n) {
    root[uf.root(i)].push_back(i);
  }
  map<int, vector<int>> need;
  vector<int> one, two;
  for(auto [rt, vs]: root) {
    need[rt] = vector<int>();
    for(auto v: vs) {
      rep(i, D[v]-cnt[v]) {
        need[rt].push_back(v);
      }
    }
    if(need[rt].empty()) ok = false;
    if(need[rt].size() == 1) one.push_back(rt);
    else two.push_back(rt);
  }
  int two_sum = 0;
  for(auto rt: two) two_sum += need[rt].size();
  if(two.size() == 0) {
    if(one.size() == 2) {
      cout << need[one[0]][0]+1 << ' ' << need[one[1]][0]+1 << endk;
      return 0;
    } else {
      ok = false;
    }
  } else {
    if(two_sum-((int)two.size()-1)*2 != (int)one.size()) ok = false;
  }
  if(!ok) {
    cout << -1 << endk;
    return 0;
  }
  vector<int> V;
  vector<pair<int, int>> ans;
  rep(i, two.size()) {
    auto two_root = two[i];
    auto two_verts = need[two_root];
    if(i) {
      auto back = V.back();
      V.pop_back();
      auto back2 = two_verts.back();
      two_verts.pop_back();
      ans.push_back({back, back2});
    }
    for(auto v: two_verts) {
      V.push_back(v);
    }
  }
  // assert(one.size() == V.size());
  for(auto one_root: one) {
    ans.push_back({need[one_root].back(), V.back()});
    V.pop_back();
  }
  // assert(V.empty());
  // assert(ans.size() == n-m-1);
  for(auto [u, v]: ans) {
    cout << u+1 << ' ' << v+1 << endk;
  }
  return 0;
}
