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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> sum(n);
  vector<int> depth(n);
  auto dfs = [&](auto dfs, int cur, int par) -> ll {
    depth[cur] = (par == -1 ? 0 : depth[par]+1);
    sum[cur] += A[cur];
    for(int ne: G[cur]) {
      if(ne != par) sum[cur] += dfs(dfs, ne, cur);
    }
    return sum[cur];
  };
  dfs(dfs, 0, -1);
  // cout << sum << endk;
  ll mx = 0;
  ll tmp = 0;
  rep(i, n) tmp += depth[i] * A[i];
  auto dfs2 = [&](auto dfs2, int cur, int par, ll val) -> void {
    // cout << cur+1 << ' ' << val << endk;
    chmax(mx, val);
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs2(dfs2, ne, cur, val+(sum[0]-sum[ne])-sum[ne]);
      }
    }
  };
  dfs2(dfs2, 0, -1, tmp);
  cout << mx << endk;
  return 0;
}
