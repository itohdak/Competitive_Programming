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
  vector<string> S(4); rep(i, 4) cin >> S[i];
  vector<ld> dp(1<<16, longinf);
  dp[0] = 0;
  rep(x, 1<<16) {
    if(x == 0) continue;
    rep(i, 4) rep(j, 4) {
      ld sum = 5;
      int cnt = 0;
      int dx[] = {0, 1, 0, -1, 0};
      int dy[] = {0, 0, -1, 0, 1};
      rep(k, 5) {
        int ni = i+dx[k];
        int nj = j+dy[k];
        int ne = ni*4+nj;
        if(ni < 0 || ni >= 4 || nj < 0 || nj >= 4) continue;
        if((x>>ne)&1) {
          sum += dp[x^(1<<ne)];
          cnt++;
        }
      }
      if(cnt) {
        chmin(dp[x], sum / cnt);
      }
    }
  }
  int x = 0;
  rep(i, 4) rep(j, 4) {
    if(S[i][j] == '#') x ^= 1<<(i*4+j);
  }
  cout << setprecision(10) << fixed << dp[x] << endk;
  return 0;
}
