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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<pair<int, int>> P(k);
  rep(i, k) {
    int r, c; cin >> r >> c;
    r--; c--;
    P[i] = {r, c};
  }
  sort(all(P));
  map<pair<int, int>, int> mp;
  rep(i, k) {
    auto [r, c] = P[i];
    mp[P[i]] = i;
  }
  bool include_bottom_right = true;
  if(P.back() != make_pair(n-1, m-1)) {
    include_bottom_right = false;
    P.push_back({n-1, m-1});
    k++;
  }
  vector<vector<edge>> G(k+n+m);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, k) {
    auto [r, c] = P[i];
    if(P[i] != make_pair(n-1, m-1) || include_bottom_right) {
      rep(j, 4) {
        pair<int, int> ne = {r+dx[j], c+dy[j]};
        if(mp.count(ne)) {
          G[i].push_back({mp[ne], 0});
        }
      }
      if(r-1 >= 0) {
        G[i].push_back({k+r-1, 1});
        G[k+r-1].push_back({i, 0});
      }
      if(r+1 < n) {
        G[i].push_back({k+r+1, 1});
        G[k+r+1].push_back({i, 0});
      }
      if(c-1 >= 0) {
        G[i].push_back({k+n+c-1, 1});
        G[k+n+c-1].push_back({i, 0});
      }
      if(c+1 < m) {
        G[i].push_back({k+n+c+1, 1});
        G[k+n+c+1].push_back({i, 0});
      }
      G[i].push_back({k+r, 1});
      G[i].push_back({k+n+c, 1});
    }
    G[k+r].push_back({i, 0});
    G[k+n+c].push_back({i, 0});
  }
  dijkstra(0, k+n+m, G);
  cout << (d[k-1] == longinf ? -1 : d[k-1]) << endk;
  return 0;
}
