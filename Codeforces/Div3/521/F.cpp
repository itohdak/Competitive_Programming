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
  int n, k, x; cin >> n >> k >> x;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(x+1, vector<ll>(k, -longinf)));
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, x+1) {
      rep(l, k) {
        if(l < k-1) chmax(dp[i+1][j][l+1], dp[i][j][l]);
        if(j < x) chmax(dp[i+1][j+1][0], dp[i][j][l]+A[i]);
      }
    }
  }
  ll mx = *max_element(all(dp[n][x]));
  cout << (mx < 0 ? -1 : mx) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
