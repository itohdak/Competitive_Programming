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
  int n, h, l, r; cin >> n >> h >> l >> r;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> sum(n+1); rep(i, n) sum[i+1] = sum[i] + A[i];
  vector<vector<int>> dp(n+1, vector<int>(n+1)); // 何時間前倒しているか
  rep(i, n) {
    rep(j, i+1) {
      int now = sum[i] + h * i - j;
      int next = (now + A[i]) % h;
      int next2 = (now + A[i] - 1) % h;
      chmax(dp[i+1][j], dp[i][j]+(l <= next && next <= r));
      if(j+1 < n+1) chmax(dp[i+1][j+1], dp[i][j]+(l <= next2 && next2 <= r));
    }
  }
  cout << *max_element(all(dp[n])) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
