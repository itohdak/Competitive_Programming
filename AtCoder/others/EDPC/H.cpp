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
  vector<vector<ll>> dp(h, vector<ll>(w));
  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    int dx[] = {0, 1};
    int dy[] = {1, 0};
    rep(k, 2) {
      int ni = i+dx[k], nj = j+dy[k];
      if(ni >= h || nj >= w) continue;
      if(S[ni][nj] == '#') continue;
      (dp[ni][nj] += dp[i][j]) %= mod;
    }
  }
  cout << dp[h-1][w-1] << endk;
  return 0;
}
