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
  vector<int> A(n), B(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    A[i] = a;
    B[i] = b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> in(n), out(n);
  int tmp = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    in[cur] = tmp++;
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
    }
    out[cur] = tmp++;
  };
  dfs(dfs, 0, -1);
  int q;
  cin >> q;
  vector<ll> ans(n);
  rep(_, q) {
    int t, e; ll x;
    cin >> t >> e >> x;
    e--;
    if(t == 1) {
      if(in[A[e]] <= in[B[e]] && out[B[e]] <= out[A[e]]) { // Bが下
        ans[0] += x;
        ans[B[e]] -= x;
      } else { // Aが下
        ans[A[e]] += x;
      }
    } else {
      if(in[A[e]] <= in[B[e]] && out[B[e]] <= out[A[e]]) { // Bが下
        ans[B[e]] += x;
      } else { // Aが下
        ans[0] += x;
        ans[A[e]] -= x;

      }
    }
  }
  // cout << ans << endk;
  auto dfs2 = [&](auto dfs2, int cur, int par) -> void {
    if(par != -1) ans[cur] += ans[par];
    for(int ne: G[cur]) {
      if(ne != par) dfs2(dfs2, ne, cur);
    }
  };
  dfs2(dfs2, 0, -1);
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
