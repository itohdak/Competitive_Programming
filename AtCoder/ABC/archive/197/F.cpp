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
  vector<pair<int, int>> P;
  map<char, vector<pair<int, int>>> mp;
  rep(i, m) {
    int a, b; char c;
    cin >> a >> b >> c;
    a--; b--;
    P.push_back({a, b});
    mp[c].push_back({a, b});
  }
  vector<vector<edge>> G(n*n);
  auto id = [&](int x, int y) {
    return x*n+y;
  };
  for(auto [_, pairs]: mp) {
    int sz = pairs.size();
    rep(i, sz) rep(j, sz) {
      auto [a1, b1] = pairs[i];
      auto [a2, b2] = pairs[j];
      G[id(a1, a2)].push_back({id(b1, b2), 2});
      G[id(a1, b2)].push_back({id(b1, a2), 2});
      G[id(b1, a2)].push_back({id(a1, b2), 2});
      G[id(b1, b2)].push_back({id(a1, a2), 2});
    }
  }
  dijkstra(n*n, G, id(0, n-1));
  ll ans = longinf;
  rep(i, n) chmin(ans, dist[id(i, i)]);
  for(auto [a, b]: P) {
    chmin(ans, dist[id(a, b)]+1);
    chmin(ans, dist[id(b, a)]+1);
  }
  cout << (ans==longinf ? -1 : ans) << endk;
  return 0;
}
