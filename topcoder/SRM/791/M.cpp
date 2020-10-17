#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

class RandomDijkstraDiv1 {
public:
  vector<ll> d;
  void dijkstra(int s, int N, vector<vector<edge>>& G) {
    priority_queue<P, vector<P>, greater<P>> que;
    d = vector<ll>(N, longinf);
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
        }
      }
    }
  }
  double solve(int n, vector<int> _G) {
    vector<vector<edge>> G(n);
    rep(i, n) rep(j, n) {
      if(i == j) continue;
      G[i].push_back({j, _G[i*n+j]});
    }
    dijkstra(0, n, G);
    vector<int> par(n);
    rep(i, n) rep(j, n) {
      if(d[i] + _G[i*n+j] == d[j]) par[j] += (1<<i);
    }
    vector<vector<ll>> dp(n+1, vector<ll>(1<<n));
    ll ans = dp[n][(1<<n)-1];
    ll cnt = 1;
    rep(i, n) cnt *= (i+1);
    return (double)ans/cnt;
  }
};

int main() {
  int n = 5;
  vector<int> _G = {
    0, 1000, 1000,    4,    5,
    1000,    0, 1000, 1000, 1000,
    1000,    2,    0, 1000, 1000,
    1000, 1000,    6,    0, 1000,
    1000,    7, 1000, 1000,    0
  };
  cout << RandomDijkstraDiv1().solve(n, _G) << endl;
}
