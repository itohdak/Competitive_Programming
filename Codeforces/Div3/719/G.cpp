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

void solve() {
  int n, m; ll w; cin >> n >> m >> w;
  vector<vector<ll>> A(n, vector<ll>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  auto bfs = [&](int s) {
    vector<int> dist(n*m, inf);
    queue<pair<int, int>> q;
    q.push({s, 0});
    dist[s] = 0;
    vector<bool> vis(n*m);
    while(!q.empty()) {
      auto [cur, d] = q.front(); q.pop();
      if(vis[cur]) continue;
      if(dist[cur] < d) continue;
      vis[cur] = true;
      int x=cur/m, y=cur%m;
      int dx[] = {-1, 0, 1, 0};
      int dy[] = {0, 1, 0, -1};
      rep(k, 4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(A[nx][ny] == -1) continue;
        int ne = nx*m+ny;
        if(dist[ne] > dist[cur] + 1) {
          dist[ne] = dist[cur] + 1;
          q.push({ne, dist[ne]});
        }
      }
    }
    return dist;
  };
  auto D1 = bfs(0);
  auto D2 = bfs(n*m-1);
  ll mn1 = longinf, mn2 = longinf;
  rep(i, n) rep(j, m) {
    if(A[i][j] > 0 && D1[i*m+j] != inf) chmin(mn1, D1[i*m+j]*w+A[i][j]);
    if(A[i][j] > 0 && D2[i*m+j] != inf) chmin(mn2, D2[i*m+j]*w+A[i][j]);
  }
  ll ans = longinf;
  if(D1[n*m-1] != inf) chmin(ans, D1[n*m-1]*w);
  chmin(ans, mn1+mn2);
  cout << (ans==longinf ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
