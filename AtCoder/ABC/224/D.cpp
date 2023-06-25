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
  int m; cin >> m;
  vector<vector<int>> G(9);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> P(9);
  int sum = 0;
  rep(i, 9) sum += i;
  rep(i, 8) {
    cin >> P[i];
    P[i]--;
    sum -= P[i];
  }
  P[8] = sum;
  // cout << P << endk;
  map<vector<int>, int> dist;
  set<vector<int>> vis;
  queue<pair<int, vector<int>>> q;
  q.push({0, P});
  dist[P] = 0;
  while(q.size()) {
    auto [d, cur] = q.front(); q.pop();
    // cout << cur << endk;
    if(vis.count(cur)) continue;
    if(d > dist[cur]) continue;
    for(int ne: G[cur[8]]) {
      vector<int> next = cur;
      int p = -1;
      rep(i, 9) if(next[i] == ne) p = i;
      swap(next[p], next[8]);
      if(!dist.count(next) || dist[next] > d+1) {
        dist[next] = d+1;
        q.push({dist[next], next});
      }
    }
  }
  vector<int> g(9);
  iota(all(g), 0);
  if(!dist.count(g)) cout << -1 << endk;
  else cout << dist[g] << endk;
  return 0;
}
