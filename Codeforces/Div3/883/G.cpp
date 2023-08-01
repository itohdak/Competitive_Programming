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

void solve() {
  int n, m; cin >> n >> m;
  string S; cin >> S;
  int s = 0;
  rep(i, n) if(S[i] == '1') s += 1<<i;
  vector<vector<edge>> G(1<<n);
  rep(i, m) {
    ll d; cin >> d;
    string F, T; cin >> F >> T;
    int f = 0, t = 0;
    rep(j, n) {
      if(F[j] == '1') f += 1<<j;
      if(T[j] == '1') t += 1<<j;
    }
    rep(j, 1<<n) {
      // cout << j << ' ' << ((j&(~f))|t) << ' ' << d << endk;
      G[j].push_back({((j&(~f))|t), d});
    }
  }
  dijkstra(1<<n, G, s);
  if(dist[0] == longinf) cout << -1 << endk;
  else cout << dist[0] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
