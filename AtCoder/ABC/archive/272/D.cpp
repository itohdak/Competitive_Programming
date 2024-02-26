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
  map<int, int> pw;
  rep(i, 401) {
    pw[i*i] = i;
  }
  vector<bool> vis(n*n);
  vector<int> dist(n*n, inf);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while(q.size()) {
    int cur = q.front(); q.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    int x = cur/n, y = cur%n;
    rep(i, n) {
      int dx = i;
      int diff = m - dx*dx;
      if(diff < 0) continue;
      if(!pw.count(diff)) continue;
      int dy = pw[diff];
      int fx[] = {-1, -1, 1, 1};
      int fy[] = {-1, 1, -1, 1};
      rep(k, 4) {
        int nx = x + fx[k]*dx;
        int ny = y + fy[k]*dy;
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        int ne = nx*n+ny;
        if(!vis[ne]) {
          dist[ne] = dist[cur]+1;
          q.push({ne});
        }
      }
    }
  }
  rep(i, n) {
    rep(j, n) {
      cout << (dist[i*n+j] == inf ? -1 : dist[i*n+j]) << ' ';
    }
    cout << endk;
  }
  return 0;
}
