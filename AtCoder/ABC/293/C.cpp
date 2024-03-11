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
  vector<vector<int>> A(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  set<int> st;
  int ans = 0;
  auto dfs = [&](auto dfs, int x, int y) -> void {
    if(st.count(A[x][y])) return;
    if(x == h-1 && y == w-1) {
      ans++;
      return;
    }
    st.insert(A[x][y]);
    int dx[] = {0, 1};
    int dy[] = {1, 0};
    rep(d, 2) {
      int nx = x+dx[d], ny = y+dy[d];
      if(nx >= h || ny >= w) continue;
      dfs(dfs, nx, ny);
    }
    st.erase(A[x][y]);
  };
  dfs(dfs, 0, 0);
  cout << ans << endk;
  return 0;
}
