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
  vector<vector<pair<int, ll>>> G(n);
  rep(i, n-1) {
    int u, v; ll w;
    cin >> u >> v >> w;
    u--; v--;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  int MAX = 60;
  vector<vector<vector<int>>> cnt(n, vector<vector<int>>(MAX, vector<int>(2)));
  ll ans = 0;
  vector<ll> pw(MAX);
  pw[0] = 1;
  rep(i, MAX) if(i) pw[i] = pw[i-1]*2%mod;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    rep(i, MAX) {
      cnt[cur][i][0]++;
    }
    for(auto [ne, w]: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      rep(i, MAX) {
        if((w>>i)&1) {
          (ans += pw[i] * cnt[ne][i][1] % mod * cnt[cur][i][1] % mod) %= mod;
          (ans += pw[i] * cnt[ne][i][0] % mod * cnt[cur][i][0] % mod) %= mod;
          cnt[cur][i][1] += cnt[ne][i][0];
          cnt[cur][i][0] += cnt[ne][i][1];
        } else {
          (ans += pw[i] * cnt[ne][i][0] % mod * cnt[cur][i][1] % mod) %= mod;
          (ans += pw[i] * cnt[ne][i][1] % mod * cnt[cur][i][0] % mod) %= mod;
          cnt[cur][i][0] += cnt[ne][i][0];
          cnt[cur][i][1] += cnt[ne][i][1];
        }
      }
    }
  };
  dfs(dfs, 0, -1);
  cout << ans << endk;
  return 0;
}
