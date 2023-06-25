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
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> vis(n);
  vector<int> v;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    v.push_back(cur);
    vis[cur] = true;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      if(vis[ne]) continue;
      dfs(dfs, ne, cur);
    }
  };
  vector<vector<int>> cnt;
  map<int, int> pos;
  ll tmp = 0;
  auto dfs2 = [&](auto dfs2, int i) -> void {
    if(i == v.size()) {
      tmp++;
      return;
    }
    rep(j, 3) {
      if(cnt[i][j]) continue;
      for(int ne: G[v[i]]) {
        if(pos[ne] < i) continue;
        cnt[pos[ne]][j]++;
      }
      dfs2(dfs2, i+1);
      for(int ne: G[v[i]]) {
        if(pos[ne] < i) continue;
        cnt[pos[ne]][j]--;
      }
    }
  };
  ll ans = 1;
  rep(i, n) {
    if(vis[i]) continue;
    v.clear();
    dfs(dfs, i, -1);
    cnt.assign(v.size(), vector<int>(3));
    pos.clear();
    tmp = 0;
    rep(i, v.size()) pos[v[i]] = i;
    dfs2(dfs2, 0);
    ans *= tmp;
  }
  cout << ans << endk;
  return 0;
}
