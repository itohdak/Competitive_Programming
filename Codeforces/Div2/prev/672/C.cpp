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
  int n, q; cin >> n >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> dp(n+1, vector<ll>(2, -longinf));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, 2) {
      chmax(dp[i+1][j], dp[i][j]);
      chmax(dp[i+1][1-j], dp[i][j]+(j ? -1 : 1)*A[i]);
    }
  }
  cout << *max_element(all(dp[n])) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
