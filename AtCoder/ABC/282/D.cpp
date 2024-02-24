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
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bool ok = true;
  vector<int> C(n, -1);
  vector<int> R(n, -1);
  auto dfs = [&](auto dfs, int cur, int root) -> void {
    for(int ne: G[cur]) {
      if(C[ne] != -1) {
        if(C[ne] == C[cur]) {
          ok = false;
          return;
        }
      } else {
        C[ne] = 1-C[cur];
        R[ne] = root;
        dfs(dfs, ne, root);
        if(!ok) return;
      }
    }
  };
  rep(i, n) {
    if(C[i] == -1) {
      C[i] = 0;
      R[i] = i;
      dfs(dfs, i, i);
    }
  }
  if(!ok) {
    cout << 0 << endk;
  } else {
    map<int, vector<int>> mp;
    rep(i, n) mp[R[i]].push_back(i);
    ll ans1 = 0, ans2 = 0;
    for(auto [k, v]: mp) {
      ans1 += 1LL * v.size() * (n-v.size());
      vector<vector<int>> grp(2);
      for(int i: v) grp[C[i]].push_back(i);
      ans2 += 1LL * grp[0].size() * grp[1].size();
    }
    ans1 /= 2;
    ans2 -= m;
    cout << ans1 + ans2 << endk;
  }
  return 0;
}
