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
  vector<int> D(n);
  rep(i, n) cin >> D[i];
  int l1, c1, k1; cin >> l1 >> c1 >> k1;
  int l2, c2, k2; cin >> l2 >> c2 >> k2;
  vector<vector<int>> dp(n+1, vector<int>(k1+1, inf));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, k1+1) {
      rep(k, k1-j+1) {
	int req = (max(0LL, (D[i]-1LL*l1*k))+l2-1)/l2;
	if(dp[i][j]+req > k2) continue;
	chmin(dp[i+1][j+k], dp[i][j]+req);
      }
    }
  }
  ll ans = longinf;
  rep(j, k1+1) {
    if(dp[n][j] == inf) continue;
    chmin(ans, 1LL*c1*j+1LL*c2*dp[n][j]);
  }
  cout << (ans == longinf ? -1 : ans) << endk;
  return 0;
}
