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
  int n; cin >> n;
  vector<vector<int>> G(n);
  vector<vector<int>> from(n);
  rep(i, n) {
    int k; cin >> k;
    rep(j, k) {
      int a; cin >> a;
      a--;
      G[a].push_back(i);
      from[i].push_back(a);
    }
  }
  vector<bool> seen(n), finished(n);
  vector<int> tpl;
  auto dfs = [&](auto dfs, int cur, int par) -> bool {
    if(seen[cur] && !finished[cur]) return true;
    if(seen[cur] || finished[cur]) return false;
    seen[cur] = true;
    bool ret = false;
    for(int ne: G[cur]) {
      // if(ne == par) continue;
      ret |= dfs(dfs, ne, cur);
    }
    finished[cur] = true;
    tpl.push_back(cur);
    return ret;
  };
  bool ret = false;
  rep(i, n) ret |= dfs(dfs, i, -1);
  if(ret) {
    cout << -1 << endk;
  } else {
    reverse(all(tpl));
    vector<int> dist(n, inf);
    for(int i: tpl) {
      if(from[i].size() == 0) dist[i] = 1;
      for(int ne: G[i]) {
        if(dist[ne] == inf) dist[ne] = dist[i]+(ne<i);
        else chmax(dist[ne], dist[i]+(ne<i));
      }
    }
    int mx = *max_element(all(dist));
    cout << (mx == inf ? -1 : mx) << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
