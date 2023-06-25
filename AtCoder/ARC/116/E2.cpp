#include <bits/stdc++.h>
using namespace std;
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
  int n, k; cin >> n >> k;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  auto test = [&](int x) {
    int need = 0;
    vector<int> dist(n);
    auto dfs = [&](auto dfs, int cur, int par) -> void {
      vector<int> tmp;
      for(int ne: G[cur]) {
        if(ne != par) {
          dfs(dfs, ne, cur);
          chmax(dist[cur], dist[ne]+1);
          tmp.push_back(dist[ne]+1);
        }
      }
      if(tmp.empty()) return;
      sort(all(tmp));
      int mn = *tmp.begin();
      int mx = *tmp.rbegin();
      if(mn + mx < 0) {
        chmin(dist[cur], mn);
        return;
      }
      if(cur == 0 || dist[cur] == x) {
        need++;
        dist[cur] = -x-1;
      }
    };
    dfs(dfs, 0, -1);
    return need <= k;
  };
  auto bsearch = [&]() {
    int ok = n-1, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
