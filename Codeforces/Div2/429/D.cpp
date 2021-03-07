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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> D(n); rep(i, n) cin >> D[i];
  vector<vector<int>> G(n);
  map<pair<int, int>, int> mp;
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    if(u > v) swap(u, v);
    G[u].push_back(v);
    G[v].push_back(u);
    mp[{u, v}] = i;
  }
  int parity = 0;
  vector<int> v;
  rep(i, n) {
    if(D[i] != -1) {
      parity ^= D[i];
    } else {
      v.push_back(i);
      D[i] = 0;
    }
  }
  if(parity && v.empty()) {
    cout << -1 << endk;
    return 0;
  }
  if(parity) D[v[0]] = 1;
  vector<bool> vis(n);
  vector<int> E;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    vis[cur] = true;
    for(int ne: G[cur]) {
      if(!vis[ne]) {
        dfs(dfs, ne, cur);
      }
    }
    if(D[cur]) {
      assert(par != -1);
      D[par] ^= 1;
      pair<int, int> e = {min(par, cur), max(par, cur)};
      assert(mp.count(e));
      E.push_back(mp[e]);
    }
  };
  dfs(dfs, 0, -1);
  sort(all(E));
  cout << E.size() << endk;
  for(int e: E) cout << e+1 << endk;
  return 0;
}
