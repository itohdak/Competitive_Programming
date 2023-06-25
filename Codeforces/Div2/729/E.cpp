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

#define MAX_N 55
ll C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i;
    C[i][i] = 1;
    C[0][i] = 1;
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}
ll comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}

void solve() {
  make();
  int n, mod; cin >> n >> mod;
  int mx = n*(n-1)/2;
  vector<vector<ll>> dp(n+1, vector<ll>(mx+1));
  dp[0][0] = 1;
  for(int i=1; i<=n; i++) { // 個数
    for(int j=1; j<=i; j++) { // 先頭
      rep(k, mx+1) { // ここまでの転倒数
        for(int l=0; l<=j-1; l++) { // 先頭より小さい数の個数
          if(k+l >= mx+1) continue;
          dp[i][k+l] += dp[i-1][k] * comb(j-1, l);
        }
      }
    }
  }
  cout << dp << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
