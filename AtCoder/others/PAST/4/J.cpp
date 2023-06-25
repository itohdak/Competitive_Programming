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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> X(3); rep(i, 3) cin >> X[i];
  vector<vector<ll>> C = {{0, X[0], X[1]},
                          {X[0], 0, X[2]},
                          {X[1], X[2], 0}};
  string s; cin >> s;
  vector<vector<edge>> G(n);
  rep(i, m) {
    int a, b; ll c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  vector<ll> dist;
  vector<int> par;
  vector<bool> vis(3); // A, B, C
  auto dijkstra = [&]() {
    priority_queue<P, vector<P>, greater<P>> q;
    dist.assign(n, longinf);
    par.assign(n, -1);
    dist[0] = 0;
    q.push({0, 0});
    while(q.size()) {
      auto [d, cur] = q.top(); q.pop();
      if(dist[cur] < d) continue;
      if(!vis[s[cur]-'A']) {
        rep(ne, n) {
          if(s[ne] == s[cur]) continue;
          if(dist[ne] > dist[cur] + C[s[cur]-'A'][s[ne]-'A']) {
            dist[ne] = dist[cur] + C[s[cur]-'A'][s[ne]-'A'];
            q.push({dist[ne], ne});
            par[ne] = cur;
          }
        }
        vis[s[cur]-'A'] = true;
      }
      for(auto [ne, cost]: G[cur]) {
        if(dist[ne] > dist[cur] + cost) {
          dist[ne] = dist[cur] + cost;
          q.push({dist[ne], ne});
          par[ne] = cur;
        }
      }
    }
  };
  dijkstra();
  cout << dist[n-1] << endk;
  return 0;
}
