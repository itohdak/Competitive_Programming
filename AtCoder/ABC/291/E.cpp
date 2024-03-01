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
  vector<set<int>> G(n);
  rep(i, m) {
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].insert(y);
  }
  vector<int> tpl;
  vector<bool> vis(n);
  auto dfs = [&](auto dfs, int cur) {
    if(vis[cur]) return;
    vis[cur] = true;
    for(int ne: G[cur]) dfs(dfs, ne);
    tpl.push_back(cur);
  };
  rep(i, n) dfs(dfs, i);
  reverse(all(tpl));
  vector<int> ans(n);
  vector<int> pos(n);
  rep(i, n) {
    ans[tpl[i]] = i;
    pos[i] = tpl[i];
  }
  bool ok = true;
  rep(i, n-1) {
    if(!G[pos[i]].count(pos[i+1])) ok = false;
  }
  cout << (ok ? "Yes" : "No") << endk;
  if(ok) {
    rep(i, n) cout << ans[i]+1 << ' ';
    cout << endk;
  }
  return 0;
}
