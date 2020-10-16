#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  int n; cin >> n;
  vector<ll> R(3); rep(i, 3) cin >> R[i];
  ll d; cin >> d;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> dp(n+1, vector<ll>(2, longinf));
  dp[0][0] = 0;
  rep(i, n) {
    chmin(dp[i+1][0], dp[i][0]+R[0]*A[i]+R[2]);
    chmin(dp[i+1][0], dp[i][1]+R[0]*A[i]+R[2]+(i==n-1 ? -d : 0));
    chmin(dp[i+1][1], dp[i][0]+min(R[0]*(A[i]+1), R[1])+R[0]+2*d);
    chmin(dp[i+1][0], dp[i][1]+min(R[0]*(A[i]+1), R[1])+R[0]);
  }
  // cout << dp << endk;
  cout << min(dp[n][0], dp[n][1])+d*(n-1) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
