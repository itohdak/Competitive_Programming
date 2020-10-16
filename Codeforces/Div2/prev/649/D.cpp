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

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if(m == n-1) { // tree
    vector<bool> col(n);
    auto dfs2 = [&](auto dfs2, int cur, int par) -> void {
      col[cur] = (par==-1 ? true : !col[par]);
      for(int ne: G[cur]) {
        if(ne != par) dfs2(dfs2, ne, cur);
      }
    };
    dfs2(dfs2, 0, -1);
    int sum = accumulate(all(col), 0);
    int i = 0;
    int rem = (k+1)/2;
    cout << 1 << endk;
    while(rem) {
      if(!(col[i]^(sum>=(k+1)/2))) {
        cout << i+1 << ' ';
        rem--;
      }
      i++;
    }
    cout << endk;
    return;
  }
  vector<int> path;
  vector<int> curPath;
  vector<bool> inPath(n);
  vector<bool> vis(n);
  bool loop = false;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(loop) return;
    if(inPath[cur]) {
      loop = true;
      auto itr = find(all(path), cur);
      int sz = path.end() - itr;
      curPath = vector<int>(sz);
      copy(itr, path.end(), curPath.begin());
      return;
    }
    if(vis[cur]) return;
    vis[cur] = true;
    inPath[cur] = true;
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
      if(loop) return;
    }
    inPath[cur] = false;
    path.pop_back();
  };
  rep(i, n) {
    inPath = vector<bool>(n);
    dfs(dfs, i, -1);
    if(loop) break;
  }
  bool updated = true;
  // cout << curPath << endl;
  while(updated) {
    updated = false;
    set<int> st;
    for(int v: curPath) st.insert(v);
    int sz = curPath.size();
    rep(i, sz) {
      int v = curPath[i];
      for(int ne: G[v]) {
        if(ne == curPath[(i-1+sz)%sz]) continue;
        if(st.count(ne) && ne!=curPath[(i+1)%sz]) {
          // cout << curPath << endl;
          // cout << v << " -> " << ne << endl;
          vector<int> newCurPath;
          int j = find(all(curPath), ne) - begin(curPath);
          while(j != i) {
            newCurPath.push_back(curPath[j]);
            (j+=1)%=sz;
          }
          newCurPath.push_back(curPath[j]);
          curPath = vector<int>(newCurPath.size());
          copy(all(newCurPath), begin(curPath));
          updated = true;
        }
        if(updated) break;
      }
      if(updated) break;
    }
  }
  if((int)curPath.size() > k) {
    cout << 1 << endk;
    for(int i=0, j=0; i<(k+1)/2; i++, j+=2) {
      cout << curPath[j]+1 << ' ';
    }
    cout << endk;
  } else {
    cout << 2 << endk;
    cout << curPath.size() << endk;
    for(int v: curPath) cout << v+1 << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
