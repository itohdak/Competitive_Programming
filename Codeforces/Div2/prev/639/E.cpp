#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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

#define MAX_N 200005

int N, M;
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
vector<bool> fix;
vector<vector<int>> G;
bool loop = false;
vector<int> minPar, minChild;
deque<int> L;
vector<bool> vis;
void dfs(int tmp) { // topological sort
  if(!vis[tmp]) {
    vis[tmp] = true;
    for(int ne: G[tmp]) dfs(ne);
    L.push_front(tmp);
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  fix = vector<bool>(N);
  G = vector<vector<int>>(N);
  minPar = vector<int>(N);
  minChild = vector<int>(N);
  vis = vector<bool>(N);
  rep(i, N) minPar[i] = minChild[i] = i;
  vector<vector<int>> par(N);
  UnionFind uf(N);
  rep(i, M) {
    int j, k;
    cin >> j >> k;
    --j, --k;
    G[j].push_back(k);
    par[k].push_back(j);
    uf.unite(j, k);
  }
  map<int, vector<int>> mp;
  rep(i, N) mp[uf.root(i)].push_back(i);
  for(auto m: mp) {
    L = deque<int>();
    for(int i: m.second) dfs(i);
    deque<int> Ltmp;
    set<int> finished;
    while(!L.empty()) {
      int tmp = L.front();
      Ltmp.push_front(tmp);
      L.pop_front();
      for(int ne: G[tmp]) {
        if(finished.count(ne)) loop = true;
        else minPar[ne] = min(minPar[tmp], minPar[ne]);
      }
      finished.insert(tmp);
    }
    while(!Ltmp.empty()) {
      int tmp = Ltmp.front();
      Ltmp.pop_front();
      for(int ne: par[tmp]) {
        minChild[ne] = min(minChild[tmp], minChild[ne]);
      }
    }
  }
  rep(i, N) if(i > min(minPar[i], minChild[i])) fix[i] = true;
  if(loop) {
    cout << -1 << endl;
  } else {
    string ans;
    int cnt = 0;
    rep(i, N) {
      ans += (fix[i] ? "E" : "A");
      cnt += 1-fix[i];
    }
    cout << cnt << endl;
    cout << ans << endl;
  }
  return 0;
}
