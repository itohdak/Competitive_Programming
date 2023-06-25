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
  vector<ll> W(n); rep(i, n) cin >> W[i];
  vector<vector<pair<int, ll>>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    ll c; cin >> c;
    u--; v--;
    G[u].push_back({v, c});
    G[v].push_back({u, c});
  }
  vector<multiset<ll>> st(n);
  vector<map<int, ll>> memo(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    st[cur].insert(W[cur]);
    for(auto [ne, c]: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      ll mx = *st[ne].rbegin();
      if(mx-c >= 0) {
        st[cur].insert(mx-c+W[cur]);
        memo[cur][ne] = mx-c+W[cur];
      }
    }
  };
  dfs(dfs, 0, -1);
  ll ans = 0;
  auto dfs2 = [&](auto dfs2, int cur, int par, ll val) -> void {
    chmax(ans, val+W[cur]);
    for(auto [ne, c]: G[cur]) {
      if(ne == par) continue;
      if(memo[cur].count(ne)) {
        st[cur].erase(st[cur].find(memo[cur][ne]));
      }
      ll nextVal = max(*st[cur].rbegin(), val + W[cur]) - c;
      dfs2(dfs2, ne, cur, max(nextVal, 0LL));
      if(memo[cur].count(ne)) {
        st[cur].insert(memo[cur][ne]);
      }
    }
  };
  dfs2(dfs2, 0, -1, 0);
  cout << ans << endk;
  return 0;
}
