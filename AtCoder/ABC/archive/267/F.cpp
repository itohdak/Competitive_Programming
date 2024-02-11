#include <bits/stdc++.h>
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> dist(n);
  vector<int> P(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    P[cur] = par;
    if(par != -1) dist[cur] = dist[par]+1;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
    }
  };
  dfs(dfs, 0, -1);
  int s = max_element(all(dist)) - begin(dist);
  dist = vector<int>(n);
  dfs(dfs, s, -1);
  int t = max_element(all(dist)) - begin(dist);

  vector<int> path;
  int tmp = t;
  while(tmp != s) {
    path.push_back(tmp);
    tmp = P[tmp];
  }
  path.push_back(tmp);
  reverse(all(path));
  unordered_set<int> st(all(path));

  map<int, vector<int>> paths;
  vector<int> leaf(n, -1);
  vector<int> id(n, -1);
  rep(i, n) {
    if(i == s || i == t) continue;
    if(G[i].size() == 1) {
      int tmp = i;
      vector<int> path2;
      while(!st.count(tmp)) {
        path2.push_back(tmp);
        tmp = P[tmp];
      }
      path2.push_back(tmp);
      reverse(all(path2));
      rep(j, path2.size()) {
        leaf[path2[j]] = i;
        id[path2[j]] = j;
      }
      assert(!paths.count(tmp));
      paths[i] = path2;
    }
  }

  auto get_one = [&](int u, int k) -> int {
    assert(st.count(u));
    if(max(dist[u]-dist[s], dist[t]-dist[u]) < k) {
      return -2;
    } else if(dist[u]-k >= 0) {
      return path[dist[u]-k];
    } else {
      return path[dist[u]+k];
    }
  };
  int q; cin >> q;
  rep(i, q) {
    int u, k; cin >> u >> k;
    u--;
    if(st.count(u)) {
      cout << get_one(u, k)+1 << endk;
    } else {
      assert(paths.count(leaf[u]));
      if(id[u] >= k) {
        cout << paths[leaf[u]][id[u]-k]+1 << endk;
      } else {
        cout << get_one(paths[leaf[u]].front(), k-id[u])+1 << endk;
      }
    }
  }
  return 0;
}
