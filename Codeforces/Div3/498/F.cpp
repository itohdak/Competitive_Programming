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
  int n, m; ll k; cin >> n >> m >> k;
  vector<vector<ll>> A(n, vector<ll>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  int mid = (n+m-2)/2;
  int rem = n+m-2-mid;
  map<int, map<ll, int>> cnt1, cnt2;
  auto dfs1 = [&](auto dfs1, int x, int y, int depth, ll val) -> void {
    if(depth == mid) {
      cnt1[x][val^A[x][y]]++;
      return;
    }
    if(x+1 < n) dfs1(dfs1, x+1, y, depth+1, val^A[x][y]);
    if(y+1 < m) dfs1(dfs1, x, y+1, depth+1, val^A[x][y]);
  };
  auto dfs2 = [&](auto dfs2, int x, int y, int depth, ll val) -> void {
    if(depth == rem) {
      cnt2[x][val]++;
      return;
    }
    if(x-1 >= 0) dfs2(dfs2, x-1, y, depth+1, val^A[x][y]);
    if(y-1 >= 0) dfs2(dfs2, x, y-1, depth+1, val^A[x][y]);
  };
  dfs1(dfs1, 0, 0, 0, 0);
  dfs2(dfs2, n-1, m-1, 0, 0);
  // cout << cnt1 << endk << cnt2 << endk;
  ll ans = 0;
  for(auto ele: cnt1) {
    // cout << ele.first << endk;
    // cout << ele.second << endk;
    // cout << cnt2[ele.first] << endk;
    for(auto ele2: ele.second) {
      ans += 1LL * ele2.second * cnt2[ele.first][k^ele2.first];
    }
  }
  cout << ans << endk;
  return 0;
}
