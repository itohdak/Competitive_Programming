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
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  set<int> st;
  for(int i=1; i<=n; i++) st.insert(i);
  vector<int> ans(n, -1);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    int tmp = n-G[cur].size();
    auto itr = st.upper_bound(tmp);
    assert(itr != st.begin());
    ans[cur] = *(--itr);
    if(par != -1 && (ans[cur]^ans[par]) <= min(ans[cur], ans[par])) {
      int d = 0;
      int tmp = ans[par];
      while(tmp != 1) {
        tmp >>= 1;
        d++;
      }
      auto itr2 = st.upper_bound((1<<d)-1);
      assert(itr2 != st.begin());
      ans[cur] = *(--itr2);
    }
    assert(par == -1 || (ans[cur]^ans[par]) > min(ans[cur], ans[par]));
    st.erase(ans[cur]);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
    }
  };
  dfs(dfs, 0, -1);
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
