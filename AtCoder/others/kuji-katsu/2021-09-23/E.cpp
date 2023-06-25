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
  vector<vector<ll>> A(n, vector<ll>(5));
  rep(i, n) rep(j, 5) cin >> A[i][j];
  auto bsearch = [&]() {
    auto test = [&](ll m) -> bool {
      vector<int> bit(n);
      rep(i, n) rep(j, 5) bit[i] += (A[i][j]>=m)<<j;
      vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(4, vector<bool>(1<<5)));
      dp[0][0][0] = 1;
      rep(i, n) {
        rep(j, 4) {
          rep(k, 1<<5) {
            if(!dp[i][j][k]) continue;
            dp[i+1][j][k] = true;
            if(j+1 < 4) dp[i+1][j+1][k|bit[i]] = true;
          }
        }
      }
      return dp[n][3][(1<<5)-1];
    };
    ll ok = 0, ng = longinf;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
