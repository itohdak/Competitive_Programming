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
  rep(k, 4) {
    dist[s+k] = 1;
    q.push({1, s+k});
  }
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
  int ax, ay, bx, by;
  cin >> ax >> ay;
  cin >> bx >> by;
  ax--; ay--;
  bx--; by--;
  vector<string> S(n);
  rep(i, n) {
    cin >> S[i];
  }
  vector<vector<edge>> G(n*n*4);
  rep(i, n) rep(j, n) {
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};
    if(S[i][j] == '#') continue;
    int cur = i*n+j;
    rep(k, 4) rep(l, 4) {
      if(k == l) continue;
      G[cur*4+k].push_back({cur*4+l, 1});
    }
    rep(k, 4) {
      int nx = i+dx[k], ny = j+dy[k];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(S[nx][ny] == '#') continue;
      int ne = nx*n+ny;
      G[cur*4+k].push_back({ne*4+k, 0});
    }
  }
  ll ans = longinf;
  dijkstra(n*n*4, G, (ax*n+ay)*4);
  rep(k, 4) chmin(ans, dist[(bx*n+by)*4+k]);
  cout << (ans == longinf ? -1 : ans) << endk;
  return 0;
}
