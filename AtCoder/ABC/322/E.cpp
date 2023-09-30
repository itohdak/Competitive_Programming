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
  int n, k, p; cin >> n >> k >> p;
  vector<ll> C(n);
  vector<vector<int>> A(n, vector<int>(k));
  rep(i, n) {
    cin >> C[i];
    rep(j, k) cin >> A[i][j];
  }
  int PW = 1;
  rep(i, k) PW *= p+1;
  vector<vector<ll>> dp(n+1, vector<ll>(PW, longinf));
  dp[0][0] = 0;
  rep(i, n) {
    vector<int> path;
    auto dfs = [&](auto dfs, int cur) -> void {
      if(cur == k) {
	int from = 0;
	int to = 0;
	{
	  int pw = 1;
	  rep(j, k) {
	    from += pw * path[j];
	    to += pw * min(path[j]+A[i][j], p);
	    pw *= (p+1);
	  }
	}
	chmin(dp[i+1][from], dp[i][from]);
	chmin(dp[i+1][to], dp[i][from]+C[i]);
	return;
      }
      rep(j, p+1) {
	path.push_back(j);
	dfs(dfs, cur+1);
	path.pop_back();
      }
    };
    dfs(dfs, 0);
  }
  cout << (dp[n][PW-1] == longinf ? -1 : dp[n][PW-1]) << endk;
  return 0;
}
