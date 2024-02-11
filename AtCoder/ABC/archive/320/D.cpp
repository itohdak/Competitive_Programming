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
  vector<vector<pair<int, pair<ll, ll>>>> G(n);
  rep(i, m) {
    int a, b; ll x, y; cin >> a >> b >> x >> y;
    a--; b--;
    G[a].push_back({b, {x, y}});
    G[b].push_back({a, {-x, -y}});
  }
  vector<bool> vis(n);
  vector<pair<ll, ll>> pos(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(vis[cur]) return;
    vis[cur] = true;
    auto [x, y] = pos[cur];
    for(auto [ne, diff]: G[cur]) {
      auto [dx, dy] = diff;
      if(ne != par && !vis[ne]) {
	pos[ne] = {x+dx, y+dy};
	dfs(dfs, ne, cur);
      }
    }
  };
  pos[0] = {0, 0};
  dfs(dfs, 0, -1);
  rep(i, n) {
    if(!vis[i]) {
      cout << "undecidable" << endk;
    } else {
      auto [x, y] = pos[i];
      cout << x << ' ' << y << endk;
    }
  }
  return 0;
}
