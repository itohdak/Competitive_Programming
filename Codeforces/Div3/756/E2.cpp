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
  vector<int> X(k);
  rep(i, k) {
    cin >> X[i];
    X[i]--;
  }
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> dist(n, inf);
  queue<pair<int, int>> q;
  vector<int> vis(n);
  rep(i, k) {
    dist[X[i]] = 0;
    q.push({X[i], i+1});
  }
  dist[0] = 0;
  q.push({0, k+1});
  set<int> ans;
  while(q.size()) {
    auto [cur, t] = q.front(); q.pop();
    if(vis[cur] > 0) {
      if(t == k+1) ans.insert(vis[cur]);
      continue;
    }
    if(t == k+1 && cur != 0 && G[cur].size() == 1) {
      cout << -1 << endk;
      return;
    }
    vis[cur] = t;
    for(int ne: G[cur]) {
      if(dist[ne] > dist[cur]+1) {
        chmin(dist[ne], dist[cur]+1);
        q.push({ne, t});
      } else if(t == k+1) {
        ans.insert(vis[ne]);
      }
    }
  }
  cout << ans.size() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
