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

ld dp[301][301][301];
bool ok[301][301][301];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> cnt(4);
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  rep(i, 301) rep(j, 301) rep(k, 301) ok[i][j][k] = false;
  dp[0][0][0] = 0;
  ok[0][0][0] = true;
  auto dfs = [&](auto dfs, int n1, int n2, int n3) -> ld {
    if(n1 < 0 || n2 < 0 || n3 < 0) return 0;
    if(ok[n1][n2][n3]) return dp[n1][n2][n3];
    // dp[n1][n2][n3] = 1 + dp[n1-1][n2][n3] * n1/n + dp[n1+1][n2-1][n3] * n2/n + dp[n1][n2+1][n3-1] * n3/n + dp[n1][n2][n3] * (n-n1-n2-n3)/n
    // dp[n1][n2][n3] * (n1+n2+n3) = n + dp[n1-1][n2][n3] * n1 + dp[n1+1][n2-1][n3] * n2 + dp[n1][n2+1][n3-1] * n3
    ok[n1][n2][n3] = true;
    return dp[n1][n2][n3] = (n + dfs(dfs, n1-1, n2, n3) * n1 + dfs(dfs, n1+1, n2-1, n3) * n2 + dfs(dfs, n1, n2+1, n3-1) * n3)/ (n1+n2+n3);
  };
  cout << fixed << setprecision(20) << dfs(dfs, cnt[1], cnt[2], cnt[3]) << endk;
  return 0;
}
