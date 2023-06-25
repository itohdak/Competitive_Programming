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
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> dist(n);
  auto dfs = [&](auto dfs, int cur, int par, vector<int>& dist) -> void {
    if(par != -1) dist[cur] = dist[par] + 1;
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur, dist);
      }
    }
  };
  dfs(dfs, 0, -1, dist);
  int s = max_element(all(dist)) - begin(dist);
  dist.assign(n, 0);
  dfs(dfs, s, -1, dist);
  int t = max_element(all(dist)) - begin(dist);
  vector<int> dist2(n);
  dfs(dfs, t, -1, dist2);
  vector<int> E(n);
  int tmp = 1;
  auto dfs2 = [&](auto dfs2, int cur, int par) -> void {
    E[cur] = tmp++;
    int buff = -1;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      if(dist[ne] + dist2[ne] == dist[t]) {
        buff = ne;
        continue;
      }
      dfs2(dfs2, ne, cur);
    }
    if(buff != -1) {
      dfs2(dfs2, buff, cur);
    }
    tmp++;
  };
  dfs2(dfs2, s, -1);
  rep(i, n) cout << E[i] << ' ';
  cout << endk;
  return 0;
}
