#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<ll>> A(n, vector<ll>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  if(n == 1) {
    ll ans = longinf;
    rep(i, m-1) chmin(ans, abs(A[0][i+1]-A[0][i]));
    cout << ans << endk;
    return;
  }
  vector<vector<ll>> mn(n, vector<ll>(n, longinf)); // i,jが連続のときの最小値
  vector<vector<ll>> mn2(n, vector<ll>(n, longinf)); // iが最後,jが最初のときの最小値
  rep(i, n) rep(j, n) {
    rep(k, m) {
      chmin(mn[i][j], abs(A[i][k]-A[j][k]));
    }
    rep(k, m-1) {
      chmin(mn2[i][j], abs(A[i][k]-A[j][k+1]));
    }
  }
  auto bsearch = [&]() {
    auto test = [&](ll m) {
      vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(1<<n)));
      rep(i, n) dp[i][i][1<<i] = longinf;
      rep(i, 1<<n) {
        rep(s, n) rep(t, n) {
          if(!(((i>>s)&1) && ((i>>t)&1))) continue;
          if(!dp[s][t][i]) continue;
          rep(k, n) {
            if((i>>k)&1) continue;
            if(__builtin_popcount(i) == n-1) {
              if(min(mn[t][k], mn2[k][s]) >= m) dp[s][k][i^(1<<k)] = true;
            } else {
              if(mn[t][k] >= m) dp[s][k][i^(1<<k)] = true;
            }
          }
        }
      }
      bool ret = false;
      rep(i, n) rep(j, n) {
        if(i == j) continue;
        if(dp[i][j][(1<<n)-1]) ret = true;
      }
      return ret;
    };
    ll ok = 0, ng = longinf;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
