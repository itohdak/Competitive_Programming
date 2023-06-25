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
  int n; cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];

  map<pair<int, int>, map<int, int>> mp1;
  auto dfs1 = [&](auto dfs1, int x, int y, int val, int rem) {
    if(rem == 0) {
      mp1[{x, y}][val]++;
      return;
    }
    if(x+1 < n) {
      dfs1(dfs1, x+1, y, val^A[x+1][y], rem-1);
    }
    if(y+1 < n) {
      dfs1(dfs1, x, y+1, val^A[x][y+1], rem-1);
    }
  };
  dfs1(dfs1, 0, 0, A[0][0], n-1);

  map<pair<int, int>, map<int, int>> mp2;
  auto dfs2 = [&](auto dfs2, int x, int y, int val, int rem) {
    if(rem == 0) {
      mp2[{x, y}][val]++;
      return;
    }
    if(x-1 >= 0) {
      dfs2(dfs2, x-1, y, val^A[x-1][y], rem-1);
    }
    if(y-1 >= 0) {
      dfs2(dfs2, x, y-1, val^A[x][y-1], rem-1);
    }
  };
  dfs2(dfs2, n-1, n-1, A[n-1][n-1], n-1);

  ll ans = 0;
  for(auto& [pos, mp]: mp1) {
    auto [x, y] = pos;
    if(mp2.count(pos)) {
      for(auto& [val, cnt]: mp) {
        if(mp2[pos].count(val^A[x][y])) ans += 1LL * cnt * mp2[pos][val^A[x][y]];
      }
    }
  }
  cout << ans << endk;
  return 0;
}
