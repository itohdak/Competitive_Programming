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
  ll n; int m; cin >> n >> m;
  ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  vector<tuple<ll, ll, int>> Px(m), Py(m);
  rep(i, m) {
    ll x, y; cin >> x >> y;
    Px[i] = {x, y, i};
    Py[i] = {x, y, i};
  }
  sort(all(Px));
  sort(all(Py), [&](tuple<ll, ll, int> p1, tuple<ll, ll, int> p2) {
    return get<1>(p1) < get<1>(p2);
  });
  vector<vector<edge>> G(m+2);
  rep(i, m) {
    auto [ux, uy, ui] = Px[i];
    G[m].push_back({ui, min(abs(ux-sx), abs(uy-sy))});
    G[ui].push_back({m+1, abs(ux-tx)+abs(uy-ty)});
  }
  G[m].push_back({m+1, abs(sx-tx)+abs(sy-ty)});
  rep(i, m-1) {
    auto [ux, uy, ui] = Px[i];
    auto [vx, vy, vi] = Px[i+1];
    G[ui].push_back({vi, vx-ux});
    G[vi].push_back({ui, vx-ux});
  }
  rep(i, m-1) {
    auto [ux, uy, ui] = Py[i];
    auto [vx, vy, vi] = Py[i+1];
    G[ui].push_back({vi, vy-uy});
    G[vi].push_back({ui, vy-uy});
  }
  dijkstra(m, m+2, G);
  cout << d[m+1] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
