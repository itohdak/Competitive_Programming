#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll> > dp(max(N, M)+1, vector<ll>(3));
  dp[1][0] = 1;
  REP(i, 2, max(N, M)+1) {
    dp[i][0] = dp[i-1][0];
    dp[i][1] = dp[i-1][1] + dp[i-1][2];
    dp[i][2] = dp[i-1][0] + dp[i-1][1];

    dp[i][0] %= mod;
    dp[i][1] %= mod;
    dp[i][2] %= mod;
  }
  cout <<
    2 * (dp[N][0] * dp[M][0] % mod +
         (dp[M][1] + dp[M][2]) % mod * dp[N][0] % mod +
         (dp[N][1] + dp[N][2]) % mod * dp[M][0] % mod) % mod << endl;
  return 0;
}

