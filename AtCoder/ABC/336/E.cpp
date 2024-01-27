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
  ll n; cin >> n;
  vector<int> N(15);
  rep(i, 15) {
    N[i] = n%10;
    n /= 10;
  }
  reverse(all(N));
  int mx = 9*14;
  ll ans = 0;
  REP(sm, 1, mx+1) {
    vector<int> pw(15);
    pw[0] = 1;
    rep(i, 15) if(i) pw[i] = pw[i-1]*10%sm;
    vector<vector<vector<vector<ll>>>>
      dp(2, vector<vector<vector<ll>>>(16, vector<vector<ll>>(sm+1, vector<ll>(sm))));
    dp[0][0][0][0] = 1;
    rep(i, 15) {
      rep(j, sm+1) {
	rep(k, sm) {
	  rep(l, N[i]+1) {
	    if(j+l < sm+1) {
	      dp[(l<N[i])][i+1][j+l][(k+l*pw[14-i]%sm)%sm] += dp[0][i][j][k];
	    }
	  }
	  rep(l, 10) {
	    if(j+l < sm+1) {
	      dp[1][i+1][j+l][(k+l*pw[14-i]%sm)%sm] += dp[1][i][j][k];
	    }
	  }
	}
      }
    }
    ans += dp[0][15][sm][0] + dp[1][15][sm][0];
  }
  cout << ans << endk;
  return 0;
}
