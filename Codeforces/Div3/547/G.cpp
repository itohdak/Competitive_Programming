#include <bits/stdc++.h>
#include <print.hpp>
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> G(n);
  map<pair<int, int>, int> mp;
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
    mp[{u, v}] = mp[{v, u}] = i;
  }
  auto bsearch = [&]() {
    auto test = [&](int mid) {
      int cnt = 0;
      rep(i, n) {
        if((int)G[i].size() > mid) cnt++;
      }
      return cnt <= k;
    };
    int ok = n, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  vector<int> col(n-1);
  int ans = bsearch();
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    int tmpCol = 0;
    if(par != -1) {
      tmpCol = col[mp[{par, cur}]];
    }
    (tmpCol += 1) %= ans;
    for(int ne: G[cur]) {
      if(ne != par) {
        col[mp[{cur, ne}]] = tmpCol;
        dfs(dfs, ne, cur);
        (tmpCol += 1) %= ans;
      }
    }
  };
  dfs(dfs, 0, -1);
  cout << ans << endk;
  rep(i, n-1) cout << col[i]+1 << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
