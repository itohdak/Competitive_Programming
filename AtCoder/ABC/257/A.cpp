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

vector<ll> dist;
vector<int> par;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  par.assign(n, -1);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({dist[ne], ne});
        par[ne] = cur;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<edge>> G(n);
  set<int> st;
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    if(u == -1) {
      st.insert(v);
    } else {
      G[u].push_back({v, 1});
      G[v].push_back({u, 1});
    }
  }
  dijkstra(n, G, 0);
  vector<ll> dist1 = dist;
  dist.clear();
  par.clear();
  dijkstra(n, G, n-1);
  vector<ll> dist2 = dist;
  ll mn1 = longinf;
  for(int u: st) chmin(mn1, dist2[u]);
  ll mn2 = longinf;
  for(int u: st) chmin(mn2, dist1[u]);
  rep(i, n) {
    ll ans = dist1[n-1];
    chmin(ans, dist1[i]+mn1+1);
    chmin(ans, dist2[i]+mn2+1);
    cout << (ans == longinf ? -1 : ans) << ' ';
  }
  cout << endk;
  return 0;
}
