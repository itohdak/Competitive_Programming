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
  vector<int> X(n);
  rep(i, n) cin >> X[i];
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> V(q), K(q);
  rep(i, q) {
    cin >> V[i] >> K[i];
    V[i]--;
  }
  vector<multiset<int>> vst(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    vst[cur].insert(X[cur]);
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      for(int a: vst[ne]) {
        vst[cur].insert(a);
        if(vst[cur].size() > 20) vst[cur].erase(vst[cur].begin());
      }
    }
  };
  dfs(dfs, 0, -1);
  // cout << vst << endk;
  rep(i, q) {
    auto itr = vst[V[i]].end();
    rep(j, K[i]) itr--;
    cout << *itr << endk;
  }
  return 0;
}