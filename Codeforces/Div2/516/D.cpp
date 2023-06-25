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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  int r, c; cin >> r >> c;
  r--; c--;
  ll x, y; cin >> x >> y;
  vector<string> S(n); rep(i, n) cin >> S[i];
  auto bfs = [&]() {
    vector<int> dist(n*m, inf);
    queue<tuple<int, int, ll, ll>> q;
    q.push({r*m+c, 0, x, y});
    dist[r*m+c] = 0;
    vector<bool> vis(n*m);
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while(q.size()) {
      auto [id, d, remx, remy] = q.front(); q.pop();
      int curx = id/m, cury = id%m;
      if(vis[id]) continue;
      if(dist[id] != d) continue;
      vis[id] = true;
      rep(k, 4) {
        int nex = curx+dx[k], ney = cury+dy[k];
        int ne = nex * m + ney;
        if(nex < 0 || nex >= n || ney < 0 || ney >= m) continue;
        if(S[nex][ney] == '*') continue;
        if(dist[ne] > d + (dy[k] != 0)) {
          if(dy[k] == -1) {
            if(remx > 0) {
              dist[ne] = d + (dy[k] != 0);
              q.push({ne, dist[ne], remx-1, remy});
            }
          } else if(dy[k] == 1) {
            if(remy > 0) {
              dist[ne] = d + (dy[k] != 0);
              q.push({ne, dist[ne], remx, remy-1});
            }
          } else {
            dist[ne] = d + (dy[k] != 0);
            q.push({ne, dist[ne], remx, remy});
          }
        }
      }
    }
    return dist;
  };
  auto dist = bfs();
  int ans = 0;
  rep(i, n) rep(j, m) if(dist[i*m+j] != inf) ans++;
  cout << ans << endk;
  return 0;
}
