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
  int n = 18, m = 6;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<bool>> ok(1<<(2*m), vector<bool>(1<<m));
  rep(i, 1<<m) rep(j, 1<<m) rep(k, 1<<m) {
    bool _ok = true;
    auto count = [&](int pos) {
      int ret = 0;
      ret += j>>pos&1;
      if(pos-1 >= 0) ret += j>>(pos-1)&1;
      if(pos+1 < m) ret += j>>(pos+1)&1;
      ret += i>>pos&1;
      ret += k>>pos&1;
      return ret;
    };
    rep(l, m) {
      if((count(l) >= 3)^(j>>l&1)) _ok = false;
    }
    ok[(i<<m)+j][k] = _ok;
  }
  S.push_back(string(6, '0'));
  vector<vector<ll>> dp(n+2, vector<ll>(1<<(2*m)));
  dp[0][0] = 1;
  rep(i, n+1) {
    rep(j, 1<<(2*m)) {
      rep(k, 1<<m) {
        auto check = [&]() {
          rep(j, m) {
            if(S[i][j] == '0' && (k>>j)&1) return false;
            if(S[i][j] == '1' && !((k>>j)&1)) return false;
          }
          return true;
        };
        if(!check()) continue;
        if(!ok[j][k]) continue;
        dp[i+1][((j&((1<<m)-1))<<m)+k] += dp[i][j];
      }
    }
  }
  ll ans = 0;
  rep(i, 1<<m) ans += dp[n+1][i<<m];
  cout << ans << endk;
  return 0;
}
