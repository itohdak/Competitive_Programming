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
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> dist(n);
  vector<int> in(n), out(n);
  int tmp = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    in[cur] = tmp++;
    if(par != -1) dist[cur] = dist[par] + 1;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
    }
    out[cur] = tmp++;
  };
  dfs(dfs, 0, -1);
  int mx = -1, mxd = 0;
  rep(i, n) {
    if(mxd < dist[i]) {
      mx = i;
      mxd = dist[i];
    }
  }
  rep(i, n) dist[i] = 0;
  tmp = 0;
  dfs(dfs, mx, -1);
  mx = -1, mxd = 0;
  rep(i, n) {
    if(mxd < dist[i]) {
      mx = i;
      mxd = dist[i];
    }
  }
  if(mxd&1) {
    int mid = -1;
    rep(i, n) {
      if(dist[i] == (mxd+1)/2 && in[i] <= in[mx] && out[mx] <= out[i]) {
        mid = i;
      }
    }
    rep(i, n) dist[i] = 0;
    tmp = 0;
    dfs(dfs, mid, -1);
    int cnt0 = 0, cnt1 = 0;
    rep(i, n) {
      assert(dist[i] <= (mxd+1)/2);
      if(G[i].size() > 1) continue;
      if(dist[i] == (mxd+1)/2) cnt0++;
      else if(dist[i] == mxd/2) cnt1++;
    }
    ll ans = 1LL * cnt0 * cnt1 % mod2;
    cout << ans << endk;
  } else {
    int mid = -1;
    rep(i, n) {
      if(dist[i] == mxd/2 && in[i] <= in[mx] && out[mx] <= out[i]) {
        mid = i;
      }
    }
    rep(i, n) dist[i] = 0;
    tmp = 0;
    dfs(dfs, mid, -1);
    int cnt = 0;
    rep(i, n) {
      assert(dist[i] <= mxd/2);
      if(dist[i] == mxd/2) cnt++;
    }
    ll ans = 1;
    rep(i, cnt) ((ans *= 2) %= mod2);
    (ans += (mod2 - 1 - cnt)) %= mod2;
    cout << ans << endk;
  }
  return 0;
}
