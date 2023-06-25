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

void solve() {
  ll n; cin >> n;
  vector<int> A;
  {
    ll _n = n;
    while(_n) {
      A.push_back(_n%10);
      _n /= 10;
    }
    // reverse(all(A));
  }
  int m = A.size();
  auto check = [&](int _k) -> bool {
    vector<vector<vector<bool>>> dp(m+1, vector<vector<bool>>(_k+1, vector<bool>(10)));
    // i桁目まで見て、j個使えて、繰り上がりがk
    rep(j, _k+1) dp[0][j][0] = true;
    rep(i, m) {
      rep(j, _k+1) {
        rep(k, 10) {
          if(!dp[i][j][k]) continue;
          for(int l=j; l<=3*j; l++) {
            int sum = k + l;
            assert(sum < 100);
            int c = sum / 10, s = sum % 10;
            if(s == A[i]) dp[i+1][j][c] = true;
          }
        }
      }
      rep(k, 10) {
        bool tmp = false;
        rrep(j, _k+1) {
          if(tmp) dp[i+1][j][k] = true;
          if(dp[i+1][j][k]) tmp = true;
        }
      }
    }
    // cout << dp << endl;
    return dp[m][0][0];
  };
  for(int k=1; k<=5; k++) {
    if(check(k)) {
      cout << k << endk;
      return;
    }
  }
  assert(false);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
