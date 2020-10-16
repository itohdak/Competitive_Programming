#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct edge {
  int to;
  int cost;
  edge(int t, int c): to(t), cost(c) {};
};

using P = pair<int, int>;

int N;
vector<vector<edge>> G;
void dijkstra(int s, vector<int>& d) {
  priority_queue<P, vector<P>, greater<P> > que;
  d = vector<int>(N, inf);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;

    for (int i=0; i<G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
	d[e.to] = d[v] + e.cost;
	que.push(P(d[e.to], e.to));
      }
    }
  }
}

void solve() {
  int M, A, B, C;
  cin >> N >> M >> A >> B >> C;
  --A, --B, --C;

  vector<ll> P(M), sum(M+1);
  rep(i, M) cin >> P[i];
  sort(all(P));
  rep(i, M) sum[i+1] = sum[i] + P[i];

  G = vector<vector<edge>>(N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(edge(v, 1));
    G[v].push_back(edge(u, 1));
  }
  vector<int> dA, dB, dC;
  dijkstra(A, dA);
  dijkstra(B, dB);
  dijkstra(C, dC);

  ll ans = longinf;
  rep(i, N) {
    int dsum = dA[i]+dB[i]+dC[i];
    if(dsum > M) continue;
    ans = min(sum[dB[i]]+sum[dsum], ans);
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
