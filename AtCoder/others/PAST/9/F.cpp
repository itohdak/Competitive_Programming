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
  int a, b; cin >> a >> b;
  a--; b--;
  vector<string> S(3); rep(i, 3) cin >> S[i];
  queue<int> q;
  vector<bool> vis(9*9);
  q.push(a*9+b);
  while(q.size()) {
    auto cur = q.front(); q.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    int x = cur/9, y = cur%9;
    rep(i, 3) rep(j, 3) {
      if(S[i][j] == '.') continue;
      int dx = i-1, dy = j-1;
      int nx = x+dx, ny = y+dy;
      if(nx < 0 || nx >= 9 || ny < 0 || ny >= 9) continue;
      int ne = nx*9+ny;
      if(!vis[ne]) q.push(ne);
    }
  }
  cout << accumulate(all(vis), 0) << endk;
  return 0;
}
