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
  int n, m; cin >> n >> m;
  vector<int> A(m), B(m);
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  vector<int> C(n); rep(i, n) cin >> C[i];
  vector<int> ans(m, -1);
  vector<vector<int>> G(n);
  rep(i, m) {
    if(C[A[i]] < C[B[i]]) ans[i] = 1;
    else if(C[A[i]] > C[B[i]]) ans[i] = 0;
    else {
      G[A[i]].push_back(B[i]);
      G[B[i]].push_back(A[i]);
    }
  }
  set<pair<int, int>> st;
  vector<bool> vis(n);
  vector<int> in(n), out(n);
  int id = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(vis[cur]) return;
    vis[cur] = true;
    if(par != -1) st.insert({par, cur});
    in[cur] = id++;
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
    }
    out[cur] = id++;
  };
  rep(i, n) dfs(dfs, i, -1);
  // cout << st << endk;
  rep(i, m) {
    if(ans[i] == -1) {
      if(st.count({A[i], B[i]}) || st.count({B[i], A[i]})) {
        ans[i] = (in[A[i]] < in[B[i]] && out[B[i]] < out[A[i]] ? 0 : 1);
      } else {
        ans[i] = (in[A[i]] < in[B[i]] && out[B[i]] < out[A[i]] ? 1 : 0);
      }
    }
  }
  rep(i, m) {
    cout << (ans[i] ? "<-" : "->") << endk;
  }
  return 0;
}
