#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<int>> G(n);
  rep(i, n) rep(j, n) if(S[i][j] == '1') G[i].push_back(j);
  vector<bool> vis(n);
  vector<vector<bool>> ancestor(n, vector<bool>(n));
  auto dfs = [&](auto dfs, int cur, int root) -> void {
    if(vis[cur]) return;
    vis[cur] = true;
    ancestor[cur][root] = true;
    for(int ne: G[cur]) {
      dfs(dfs, ne, root);
    }
  };
  rep(i, n) {
    vis.assign(n, false);
    dfs(dfs, i, i);
  }
  vector<int> nAncestor(n);
  rep(i, n) rep(j, n) {
    if(i == j) continue;
    nAncestor[i] += ancestor[i][j];
  }
  ld ans = 0;
  rep(i, n) ans += (ld)1/(nAncestor[i]+1);
  cout << fixed << setprecision(20) << ans << endk;
  return 0;
}