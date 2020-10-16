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
  int r, n; cin >> r >> n;
  vector<int> T(n+1), X(n+1), Y(n+1);
  rep(i, n) {
    cin >> T[i+1] >> X[i+1] >> Y[i+1];
    X[i+1]--; Y[i+1]--;
  }
  vector<int> dp(n+1, -inf);
  vector<int> mx(n+1, -inf);
  dp[0] = 0;
  rep(i, n+1) {
    rrep(j, i) {
      if(T[i]-T[j] >= 2*r) {
        chmax(dp[i], mx[j]+1);
        break;
      }
      if(abs(X[i]-X[j])+abs(Y[i]-Y[j]) <= T[i]-T[j]) {
        chmax(dp[i], dp[j]+1);
      }
    }
    chmax(mx[i], dp[i]);
    if(i) chmax(mx[i], mx[i-1]);
  }
  // cout << dp << endk;
  // cout << mx << endk;
  cout << *max_element(all(dp)) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
