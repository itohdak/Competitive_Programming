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
  int r, c; cin >> r >> c;
  vector<vector<int>> A(r, vector<int>(c-1));
  vector<vector<int>> B(r-1, vector<int>(c));
  rep(i, r) rep(j, c-1) cin >> A[i][j];
  rep(i, r-1) rep(j, c) cin >> B[i][j];
  auto id = [&](int i, int j, int k) {
    return r*c*k + i*c + j;
  };
  vector<vector<edge>> G(r*c*2);
  rep(i, r) rep(j, c-1) {
    G[id(i, j, 0)].push_back({id(i, j+1, 0), A[i][j]});
    G[id(i, j+1, 0)].push_back({id(i, j, 0), A[i][j]});
  }
  rep(i, r-1) rep(j, c) {
    G[id(i, j, 0)].push_back({id(i+1, j, 0), B[i][j]});
    G[id(i+1, j, 1)].push_back({id(i, j, 1), 1});
  }
  rep(i, r) rep(j, c) {
    G[id(i, j, 0)].push_back({id(i, j, 1), 0});
    G[id(i, j, 1)].push_back({id(i, j, 0), 1});
  }
  dijkstra(r*c*2, G, 0);
  cout << dist[r*c-1] << endk;
  return 0;
}
