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
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> path;
  vector<int> in(n), out(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    in[cur] = path.size();
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
    }
    out[cur] = path.size();
    path.push_back(cur);
  };
  dfs(dfs, 3, -1);
  vector<int> cnt_less_child(n);
  rep(i, n) {
    set<int> st;
    for(int j=in[i]+1; j<out[i]; j++) {
      if(path[j] < i) st.insert(path[j]);
    }
    cnt_less_child[i] = st.size();
  }
  cout << cnt_less_child << endk;
  vector<ll> ans(n);
  vector<ll> cnt(n);
  auto dfs2 = [&](auto dfs2, int cur, int par, ll d) -> void {
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs2(dfs2, ne, cur, d+(cur-cnt_less_child[cur]));
      cnt[cur] += cnt[ne];
    }
    ans[cur] = cnt[cur] + d + cur;
    cnt[cur] += cnt_less_child[cur];
    cout << cur << ' ' << d << ' ' << cnt << ' ' << ans << endk;
  };
  dfs2(dfs2, 3, -1, 0);
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
