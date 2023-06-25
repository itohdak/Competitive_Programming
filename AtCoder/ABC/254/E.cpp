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
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int q; cin >> q;
  rep(i, q) {
    int x, k; cin >> x >> k;
    x--;
    set<int> st;
    auto bfs = [&](int s, int n, vector<vector<int>>& G) {
      map<int, ll> dist;
      queue<pair<int, ll>> q;
      q.push({s, 0});
      dist[s] = 0;
      set<int> vis;
      while(!q.empty()) {
        auto [cur, d] = q.front(); q.pop();
        if(vis.count(cur)) continue;
        if(dist[cur] < d) continue;
        vis.insert(cur);
        for(auto ne: G[cur]) {
          if(dist[cur] + 1 > k) continue;
          if(!dist.count(ne)) dist[ne] = longinf;
          if(dist[ne] > dist[cur] + 1) {
            dist[ne] = dist[cur] + 1;
            q.push({ne, dist[ne]});
          }
        }
      }
      return dist;
    };
    ll cnt = 0;
    auto dist = bfs(x, n, G);
    for(auto [i, d]: dist) cnt += i+1;
    cout << cnt << endk;
  }
  return 0;
}
