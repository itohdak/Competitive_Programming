#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<bool> vis(n);
  vector<int> depth(n);
  vector<int> path;
  bool loop = false;
  vector<int> loopPath;
  function<void(int, int)> dfs = [&](int tmp, int par) {
    if(loop) return;
    if(vis[tmp]) {
      loop = true;
      auto begin = find(all(path), tmp);
      loopPath = vector<int>(path.end()-begin);
      copy(begin, path.end(), loopPath.begin());
      return;
    }
    vis[tmp] = true;
    depth[tmp] = depth[par]+1;
    path.push_back(tmp);
    for(int ne: G[tmp]) {
      if(ne != par) dfs(ne, tmp);
    }
    path.pop_back();
  };
  dfs(0, -1);
  if(loop) {
    set<int> se;
    vector<vector<int>> P(2);
    for(int v: loopPath) P[0].push_back(v);
    int len;
    int flag = 1;
    while(true) {
      bool update = false;
      len = P[1-flag].size();
      se.clear();
      for(int v: P[1-flag]) se.insert(v);
      rep(i, len) {
        for(int ne: G[P[1-flag][i]]) {
          if(se.count(ne) &&
             ne != P[1-flag][(i+1)%len] &&
             ne != P[1-flag][(i+len-1)%len]) {
            int end = ne;
            int tmp = i;
            P[flag] = vector<int>();
            while(P[1-flag][tmp] != end) {
              P[flag].push_back(P[1-flag][tmp]);
              tmp++;
              tmp %= len;
            }
            P[flag].push_back(P[1-flag][tmp]);
            update = true;
            break;
          }
        }
      }
      if(!update) break;
      flag = 1-flag;
    }
    if((int)P[1-flag].size() <= k) {
      cout << 2 << endl;
      cout << P[1-flag].size() << endl;
      for(int v: P[1-flag]) cout << v+1 << ' ';
      cout << endl;
    } else {
      cout << 1 << endl;
      for(int i=0, j=0; i<P[1-flag].size()&&j<(k+1)/2; i+=2, j++) {
        cout << P[1-flag][i]+1 << ' ';
      }
      cout << endl;
    }
  } else {
    int cnt = 0;
    rep(i, n) if(depth[i]%2) cnt++;
    int rem;
    if(cnt < (n+1)/2) rem = 0;
    else rem = 1;
    cout << 1 << endl;
    for(int i=0, j=0; i<n&&j<(k+1)/2; i++) {
      if(depth[i]%2==rem) {
        cout << i+1 << ' ';
        j++;
      }
    }
    cout << endl;
  }
  return 0;
}
