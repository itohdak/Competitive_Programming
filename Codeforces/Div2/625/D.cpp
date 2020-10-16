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
  int n, m; cin >> n >> m;
  vector<vector<edge>> G(n);
  vector<vector<int>> to(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[v].push_back({u, 1});
    to[u].push_back(v);
  }
  int k; cin >> k;
  vector<int> P(k);
  rep(i, k) {
    cin >> P[i];
    P[i]--;
  }
  int s = P[0], t = P[k-1];
  dijkstra(t, n, G);
  vector<set<int>> vst(n);
  rep(i, n) {
    for(int ne: to[i]) {
      if(d[i] == d[ne]+1) vst[i].insert(ne);
    }
  }
  int mn = 0, mx = 0;
  rep(i, k-1) {
    if(!vst[P[i]].count(P[i+1]) || vst[P[i]].size() > 1) mx++;
    if(!vst[P[i]].count(P[i+1])) mn++;
  }
  cout << mn << ' ' << mx << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
