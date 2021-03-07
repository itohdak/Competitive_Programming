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
  int n, m, k; cin >> n >> m >> k;
  vector<ll> H(n); rep(i, n) cin >> H[i];
  vector<int> C(k);
  rep(i, k) {
    cin >> C[i];
    C[i]--;
  }
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    if(H[a] < H[b]) G[a].push_back(b);
    else G[b].push_back(a);
  }
  vector<int> dist(n, inf);
  vector<bool> vis(n);
  auto bfs = [&]() {
    queue<pair<int, int>> q;
    // dist[id(r, c)] = 0;
    rep(i, k) {
      dist[C[i]] = 0;
      q.push({C[i], 0});
    }
    while(q.size()) {
      auto [cur, d] = q.front(); q.pop();
      if(dist[cur] != d) continue;
      if(vis[cur]) continue;
      vis[cur] = true;
      for(int ne: G[cur]) {
        if(dist[ne] > dist[cur] + 1) {
          dist[ne] = dist[cur] + 1;
          q.push({ne, dist[ne]});
        }
      }
    }
  };
  bfs();
  rep(i, n) {
    if(dist[i] == inf) cout << -1 << endk;
    else cout << dist[i] << endk;
  }
  return 0;
}
