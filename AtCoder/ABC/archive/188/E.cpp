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

vector<vector<int>> G;
vector<int> Tpl;

/* topological sort */
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}
// rep(i, N) dfs(i);
// reverse(all(Tpl));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> X(m), Y(m);
  G = vector<vector<int>>(n);
  vis = vector<bool>(n);
  rep(i, m) {
    cin >> X[i] >> Y[i];
    X[i]--; Y[i]--;
    G[X[i]].push_back(Y[i]);
  }
  rep(i, n) dfs(i);
  reverse(all(Tpl));
  vector<ll> mnp(n, longinf);
  // vector<bool> vis(n);
  // auto dfs = [&](auto dfs, int cur, int par) -> void {
  //   // cout << cur << endk;
  //   if(vis[cur]) return;
  //   vis[cur] = true;
  //   for(int ne: G[cur]) {
  //     if(ne != par) {
  //       chmin(mnp[ne], min(mnp[cur], A[cur]));
  //       // cout << cur << ' ' << ne << ' ' << min(mnp[cur], A[cur]) << endk;
  //       dfs(dfs, ne, cur);
  //     }
  //   }
  // };
  for(int cur: Tpl) {
    for(int ne: G[cur]) {
      chmin(mnp[ne], min(mnp[cur], A[cur]));
    }
  }
  // rep(i, n) dfs(dfs, i, -1);
  // cout << mnp << endk;
  ll ans = -longinf;
  rep(i, n) chmax(ans, A[i]-mnp[i]);
  cout << ans << endk;
  return 0;
}
