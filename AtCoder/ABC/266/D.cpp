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
  vector<int> T(n), X(n), A(n);
  rep(i, n) {
    cin >> T[i] >> X[i] >> A[i];
  }
  int mx = 101010;
  vector<vector<ll>> dp(mx+1, vector<ll>(5, -longinf));
  dp[0][0] = 0;
  int l = 0;
  rep(i, mx) {
    while(l < n && i == T[l]) {
      dp[T[l]][X[l]] += A[l];
      l++;
    }
    rep(j, 5) {
      for(int k=-1; k<=1; k++) {
        if(j+k >= 0 && j+k < 5) {
          chmax(dp[i+1][j+k], dp[i][j]);
        }
      }
    }
  }
  cout << *max_element(all(dp[mx])) << endk;
  return 0;
}
