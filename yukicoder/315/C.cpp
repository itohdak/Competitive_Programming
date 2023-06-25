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

ld dp[3][51][51][51][51];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, c, n; cin >> a >> b >> c >> n;
  auto dfs = [&](auto dfs, int a, int b, int c, int n, int i) -> ld {
    if(dp[i][a][b][c][n] != -1) return dp[i][a][b][c][n];
    if(a == 0 || b == 0 || c == 0 || n == 0) return dp[i][a][b][c][n] = 0;
    return dp[i][a][b][c][n] =
      (ld)(dfs(dfs, a, b, c, n-1, i) * (a*b+b*c+c*a) +
           (dfs(dfs, a-1, b, c, n-1, i)+(i==0)) * a*(a-1)/2 +
           (dfs(dfs, a, b-1, c, n-1, i)+(i==1)) * b*(b-1)/2 +
           (dfs(dfs, a, b, c-1, n-1, i)+(i==2)) * c*(c-1)/2) / ((a+b+c)*(a+b+c-1)/2);
  };
  rep(i, 3) {
    rep(a, 51) rep(b, 51) rep(c, 51) rep(j, n+1) dp[i][a][b][c][j] = -1;
    cout << fixed << setprecision(10) << dfs(dfs, a, b, c, n, i) << ' ';
  }
  cout << endk;
  return 0;
}
