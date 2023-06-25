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
  ll sat;
  edge(int t, ll c, ll sat): to(t), cost(c), sat(sat) {};
};

using P = pair<pair<ll, ll>, int>;

vector<ll> dist;
vector<ll> satisfaction;
vector<int> par;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  satisfaction.assign(n, 0);
  par.assign(n, -1);
  dist[s] = 0;
  satisfaction[s] = 0;
  q.push({{0, 0}, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d.first) continue;
    if(satisfaction[cur] < d.second) continue;
    for(auto [ne, cost, sat]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        satisfaction[ne] = d.second-sat;
        q.push({{dist[ne], d.second-sat}, ne});
        par[ne] = cur;
      } else if(dist[ne] == dist[cur] + cost) {
        if(satisfaction[ne] > d.second-sat) {
          satisfaction[ne] = d.second-sat;
          q.push({{dist[ne], d.second-sat}, ne});
          par[ne] = cur;
        }
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<edge>> G(n);
  rep(i, m) {
    int u, v; ll t; cin >> u >> v >> t;
    u--; v--;
    G[u].push_back({v, t, A[v]});
    G[v].push_back({u, t, A[u]});
  }
  dijkstra(n, G, 0);
  cout << -satisfaction[n-1]+A[0] << endk;
  return 0;
}
