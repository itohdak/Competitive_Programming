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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> G(n);
  rep(i, n) {
    if(i+A[i] < n) G[i+A[i]].push_back(i);
    if(i-A[i] >= 0) G[i-A[i]].push_back(i);
  }
  vector<int> ans(n, inf);
  auto bfs = [&](int parity) {
    queue<pair<int, int>> q;
    vector<int> dist(n, inf);
    vector<bool> vis(n);
    rep(i, n) {
      if(A[i]%2==parity) {
        q.push({0, i});
        dist[i] = 0;
      }
    }
    while(!q.empty()) {
      auto [d, cur] = q.front(); q.pop();
      if(vis[cur]) continue;
      if(dist[cur] != d) continue;
      vis[cur] = true;
      for(int ne: G[cur]) {
        if(dist[ne] > dist[cur] + 1) {
          dist[ne] = dist[cur] + 1;
          q.push({dist[ne], ne});
        }
      }
    }
    rep(i, n) {
      if(A[i]%2!=parity) {
        ans[i] = dist[i];
      }
    }
  };
  bfs(0);
  bfs(1);
  rep(i, n) cout << (ans[i] == inf ? -1 : ans[i]) << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
