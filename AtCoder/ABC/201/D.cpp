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
  rep(i, h) rep(j, w) {
    if((i+j)%2==0) {
      if(S[i][j] == '+') S[i][j] = '-';
      else S[i][j] = '+';
    }
  }
  vector<int> val(h*w);
  rep(i, h) rep(j, w) {
    if((i+j)%2) val[i*w+j] = inf;
    else val[i*w+j] = -inf;
  }
  queue<pair<int, ll>> q;
  q.push({h*w-1, 0});
  val[h*w-1] = 0;
  vector<bool> vis(h*w);
  while(!q.empty()) {
    auto [cur, d] = q.front(); q.pop();
    int x = cur/w, y = cur%w;
    if(vis[cur]) continue;
    if(val[cur] != d) continue;
    vis[cur] = true;
    int dx[] = {-1, 0};
    int dy[] = {0, -1};
    rep(k, 2) {
      int nx = x+dx[k];
      int ny = y+dy[k];
      if(nx < 0 || ny < 0) continue;
      int ne = nx*w+ny;
      int cost = (S[x][y]=='+' ? 1 : -1);
      if((nx+ny)%2) {
        if(val[ne] > val[cur] + cost) {
          val[ne] = val[cur] + cost;
          q.push({ne, val[ne]});
        }
      } else {
        if(val[ne] < val[cur] + cost) {
          val[ne] = val[cur] + cost;
          q.push({ne, val[ne]});
        }
      }
    }
  }
  // rep(i, h) {
  //   rep(j, w) {
  //     cout << val[i*w+j] << ' ';
  //   }
  //   cout << endk;
  // }
  if(val[0] == 0) {
    cout << "Draw" << endk;
  } else {
    cout << (val[0]>0 ? "Takahashi" : "Aoki") << endk;
  }
  return 0;
}
