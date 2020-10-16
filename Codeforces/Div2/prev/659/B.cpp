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
  int n, k, l; cin >> n >> k >> l;
  vector<int> D(n); rep(i, n) cin >> D[i];
  vector<int> p(2*k);
  rep(i, k) p[i] = i;
  rep(i, k) p[k+i] = k-i;
  vector<vector<bool>> ok(n, vector<bool>(2*k));
  rep(i, n) rep(j, 2*k) ok[i][j] = (D[i]+p[j]<=l);
  vector<vector<bool>> dp(n+1, vector<bool>(2*k));
  rep(j, 2*k) dp[0][j] = true;
  rep(i, n) {
    if(i) {
      rep(j, 2*k) {
        if(!ok[i][j]) continue;
        if(!dp[i][j]) continue;
        rep(m, 2*k) {
          if(!ok[i][(j+m)%(2*k)]) break;
          dp[i][(j+m)%(2*k)] = true;
        }
      }
    }
    rep(j, 2*k) {
      if(ok[i][j] && dp[i][j]) dp[i+1][(j+1)%(2*k)] = true;
    }
  }
  cout << (accumulate(all(dp[n]), 0LL) ? "YES" : "NO") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
