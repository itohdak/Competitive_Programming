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
  {
    queue<int> q;
    vector<bool> vis(n);
    rep(i, k) {
      dist[X[i]] = 0;
      q.push(X[i]);
    }
    while(q.size()) {
      int cur = q.front(); q.pop();
      if(vis[cur]) continue;
      vis[cur] = true;
      for(int ne: G[cur]) {
        if(dist[ne] > dist[cur]+1) {
          chmin(dist[ne], dist[cur]+1);
          q.push(ne);
        }
      }
    }
  }
  vector<int> dist2(n, inf);
  {
    queue<int> q;
    vector<bool> vis(n);
    dist2[0] = 0;
    q.push(0);
    while(q.size()) {
      int cur = q.front(); q.pop();
      if(vis[cur]) continue;
      vis[cur] = true;
      for(int ne: G[cur]) {
        if(dist2[ne] > dist2[cur]+1) {
          chmin(dist2[ne], dist2[cur]+1);
          q.push(ne);
        }
      }
    }
  }
  rep(i, n) {
    if(i != 0 && G[i].size() == 1 && dist2[i] < dist[i]) {
      cout << "YES" << endk;
      return;
    }
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
