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
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  int s, g;
  map<char, set<int>> mp;
  rep(i, h) rep(j, w) {
    if(S[i][j] == 'S') s = i*w+j;
    else if(S[i][j] == 'G') g = i*w+j;
    else if(S[i][j] != '.' && S[i][j] != '#') mp[S[i][j]].insert(i*w+j);
  }
  vector<bool> vis(h*w);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<int> dist(h*w, inf);
  queue<pair<int, int>> q;
  q.push({s, 0});
  dist[s] = 0;
  while(!q.empty()) {
    auto [cur, d] = q.front(); q.pop();
    if(dist[cur] != d) continue;
    if(vis[cur]) continue;
    vis[cur] = true;
    int x = cur/w;
    int y = cur%w;
    rep(k, 4) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      int ne = nx*w+ny;
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '#') continue;
      if(dist[ne] > dist[cur]+1) {
        dist[ne] = dist[cur]+1;
        q.push({ne, dist[ne]});
      }
    }
    for(int ne: mp[S[x][y]]) {
      if(dist[ne] > dist[cur]+1) {
        dist[ne] = dist[cur]+1;
        q.push({ne, dist[ne]});
      }
    }
    if(mp.count(S[x][y])) mp.erase(S[x][y]);
    // if(S[x][y] >= 'a' && S[x][y] <= 'z') {
    //   // cout << S[x][y] << ' ' << cur << endl;
    //   assert(mp[S[x][y]].count(cur));
    //   mp[S[x][y]].erase(cur);
    // }
  }
  // rep(i, h) {
  //   rep(j, w) {
  //     cout << dist[i*w+j] << ' ';
  //   }
  //   cout << endk;
  // }
  cout << (dist[g] == inf ? -1 : dist[g]) << endk;
  return 0;
}
