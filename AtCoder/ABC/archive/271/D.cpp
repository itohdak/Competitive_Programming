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
  int n, s; cin >> n >> s;
  vector<int> A(n), B(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
  }
  vector<vector<bool>> dp(n+1, vector<bool>(s+1));
  vector<vector<int>> par(n+1, vector<int>(s+1, -1));
  dp[0][0] = true;
  rep(i, n) {
    rep(j, s+1) {
      if(!dp[i][j]) continue;
      if(j+A[i] <= s) {
        dp[i+1][j+A[i]] = true;
        par[i+1][j+A[i]] = j;
      }
      if(j+B[i] <= s) {
        dp[i+1][j+B[i]] = true;
        par[i+1][j+B[i]] = j;
      }
    }
  }
  if(dp[n][s]) {
    cout << "Yes" << endk;
    string ans;
    int cur = s;
    for(int i=n; i>=1; i--) {
      assert(par[i][cur] != -1);
      int ne = par[i][cur];
      ans += (cur-ne==A[i-1] ? 'H' : 'T');
      cur = ne;
    }
    reverse(all(ans));
    cout << ans << endk;
  } else {
    cout << "No" << endk;
  }
  return 0;
}
