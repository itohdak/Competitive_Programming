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
  int n; cin >> n;
  int r1, c1; cin >> r1 >> c1;
  int r2, c2; cin >> r2 >> c2;
  r1--; c1--; r2--; c2--;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<vector<edge>> G(n*n*2);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, n*n) {
    int x = i/n, y = i%n;
    if(S[x][y] == '1') continue;
    rep(k, 4) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      int j = nx * n + ny;
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(S[nx][ny] == '1') continue;
      G[i].push_back({j, 0});
      G[i+n*n].push_back({j+n*n, 0});
    }
  }
  rep(i, n*n) {
    rep(j, n*n) {
      int x = i/n, y = i%n;
      int x2 = j/n, y2 = j%n;
      if(S[x][y] == '0' && S[x2][y2] == '0') {
        G[i].push_back({j+n*n, (x-x2)*(x-x2)+(y-y2)*(y-y2)});
      }
    }
  }
  // rep(i, n*n) for(auto [j, c]: G[i]) cout << i << ' ' << j << ' ' << c << endk;
  dijkstra(n*n*2, G, r1*n+c1);
  cout << min(dist[r2*n+c2], dist[r2*n+c2+n*n]) << endk;
  return 0;
}
