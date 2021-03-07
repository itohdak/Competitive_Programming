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
  int n, q; cin >> n >> q;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int p; cin >> p;
    p--;
    G[p].push_back(i+1);
    G[i+1].push_back(p);
  }
  rep(i, n) sort(all(G[i]));
  vector<int> in(n), out(n);
  int cnt = 0;
  vector<int> path;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    in[cur] = cnt++;
    path.push_back(cur);
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
    }
    out[cur] = cnt;
  };
  dfs(dfs, 0, -1);
  // cout << in << endk;
  // cout << out << endk;
  // cout << path << endk;
  while(q--) {
    int u, k;
    cin >> u >> k;
    u--; k--;
    if(out[u] - in[u] <= k) cout << -1 << endk;
    else cout << path[in[u]+k]+1 << endk;
  }
  return 0;
}
