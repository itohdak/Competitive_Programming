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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> d;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<edge>> G(n);
  vector<pair<int, int>> E;
  rep(i, m) {
    int x, y; ll w; cin >> x >> y >> w;
    x--; y--;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
    E.push_back({x, y});
  }
  vector<vector<ll>> dist(n);
  vector<pair<int, int>> P;
  rep(i, k) {
    int a, b; cin >> a >> b;
    a--; b--;
    P.push_back({a, b});
  }
  rep(i, n) {
    dijkstra(i, n, G);
    dist[i] = d;
  }
  // cout << dist << endk;
  ll ans = longinf;
  rep(i, m) {
    ll sum = 0;
    rep(j, k) {
      sum += min({
          dist[P[j].first][P[j].second],
          dist[P[j].first][E[i].first] + dist[E[i].second][P[j].second],
          dist[P[j].first][E[i].second] + dist[E[i].first][P[j].second]
        });
    }
    chmin(ans, sum);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
