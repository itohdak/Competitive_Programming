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
  vector<string> S(n); rep(i, n) cin >> S[i];
  int ans = inf;
  vector<vector<int>> sum(n+1, vector<int>(m+1));
  rep(i, n) rep(j, m) if(S[i][j] == 'B') sum[i+1][j+1] = 1;
  rep(i, n) rep(j, m+1) sum[i+1][j] += sum[i][j];
  rep(j, m) rep(i, n+1) sum[i][j+1] += sum[i][j];
  rep(i, n) rep(j, m) REP(k, 1, min(n, m)+1) {
    if(i+k > n || j+k > m) continue;
    int cnt = sum[i+k][j+k]-sum[i+k][j]-sum[i][j+k]+sum[i][j];
    if(sum[n][m] == cnt) chmin(ans, k*k-cnt);
  }
  cout << (ans==inf ? -1 : ans) << endk;
  return 0;
}
