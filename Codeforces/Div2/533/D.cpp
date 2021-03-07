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
  int n, m, p; cin >> n >> m >> p;
  vector<ll> S(p); rep(i, p) cin >> S[i];
  vector<string> T(n); rep(i, n) cin >> T[i];
  auto pos2id = [&](int x, int y) {
    return x * m + y;
  };
  auto id2pos = [&](int id) {
    return make_pair(id/m, id%m);
  };
  vector<queue<pair<int, int>>> q(p);
  vector<int> D(n*m, inf);
  rep(i, n) rep(j, m) {
    if('1' <= T[i][j] && T[i][j] <= '9') {
      int id = pos2id(i, j);
      D[id] = 0;
      q[T[i][j]-'1'].push({id, D[id]});
    }
  }
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<bool> vis(n*m);
  rep(t, n*m) {
    int sum = 0;
    rep(_p, p) sum += q.size();
    if(sum == 0) break;
    rep(_p, p) {
      while(q[_p].size()) {
        if(q[_p].front().second >= S[_p] * (t+1)) break;
        auto [cur, d] = q[_p].front(); q[_p].pop();
        auto [x, y] = id2pos(cur);
        if(D[cur] < d) continue;
        if(vis[cur]) continue;
        vis[cur] = true;
        T[x][y] = char('1'+_p);
        rep(k, 4) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(T[nx][ny] != '.') continue;
          int ne = pos2id(nx, ny);
          T[nx][ny] = T[x][y];
          D[ne] = D[cur] + 1;
          q[_p].push({ne, D[ne]});
        }
        // rep(i, n) cout << T[i] << endl;
        // cout << endl;
      }
    }
  }
  vector<int> ans(p);
  rep(i, n) rep(j, m) {
    if('1' <= T[i][j] && T[i][j] <= '9') ans[T[i][j]-'1']++;
  }
  rep(_p, p) cout << ans[_p] << ' ';
  cout << endk;
  return 0;
}
