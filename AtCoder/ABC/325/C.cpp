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
  vector<string> S(h);
  rep(i, h) cin >> S[i];
  queue<int> q;
  vector<bool> vis(h*w);
  int ans = 0;
  rep(i, h) rep(j, w) {
    if(S[i][j] != '#') continue;
    if(vis[i*w+j]) continue;
    ans++;
    q.push(i*w+j);
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      if(vis[cur]) continue;
      vis[cur] = true;
      int x = cur/w, y = cur%w;
      for(int dx=-1; dx<=1; dx++) {
	for(int dy=-1; dy<=1; dy++) {
	  int nx = x+dx, ny = y+dy;
	  int ne = nx*w+ny;
	  if(dx == 0 && dy == 0) continue;
	  if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
	  if(S[nx][ny] != '#') continue;
	  q.push(ne);
	}
      }
    }
  }
  cout << ans << endk;
  return 0;
}
