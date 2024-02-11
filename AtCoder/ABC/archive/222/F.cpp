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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<edge>> G(2*n);
  rep(i, n-1) {
    int a, b; ll c; cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  vector<ll> D(n); rep(i, n) cin >> D[i];
  rep(i, n) {
    G[i].push_back({n+i, D[i]});
    G[n+i].push_back({i, D[i]});
  }
  vector<vector<ll>> val(2*n), maxl(2*n+1), maxr(2*n+1);
  vector<int> nchild(2*n);
  vector<vector<edge>> E(2*n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    for(auto e: G[cur]) if(e.to != par) E[cur].push_back(e);
    nchild[cur] = E[cur].size();
    val[cur] = vector<ll>(nchild[cur]);
    maxl[cur] = vector<ll>(nchild[cur]+1);
    maxr[cur] = vector<ll>(nchild[cur]+1);
    rep(i, nchild[cur]) {
      auto [ne, cost] = E[cur][i];
      dfs(dfs, ne, cur);
      val[cur][i] = maxl[ne].back()+cost;
    }
    rep(i, nchild[cur]) {
      maxl[cur][i+1] = max(maxl[cur][i], val[cur][i]);
    }
    rrep(i, nchild[cur]) {
      maxr[cur][i] = max(maxr[cur][i+1], val[cur][i]);
    }
  };
  dfs(dfs, 0, -1);
  vector<ll> ans(2*n);
  auto dfs2 = [&](auto dfs2, int cur, int par, ll v) -> void {
    ans[cur] = max(maxl[cur][nchild[cur]-1], v);
    rep(i, nchild[cur]) {
      auto [ne, cost] = E[cur][i];
      dfs2(dfs2, ne, cur, max({v, maxl[cur][i], maxr[cur][i+1]})+cost);
    }
  };
  dfs2(dfs2, 0, -1, 0);
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
