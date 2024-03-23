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
  string s; cin >> s;
  vector<ll> C(n); rep(i, n) cin >> C[i];
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2, longinf)));
  dp[1][0][0] = 0;
  dp[1][0][1] = C[0];
  rep(i, n) {
    if(i) {
      rep(j, 2) {
        rep(k, 2) {
          rep(l, 2) {
            if((s[i]==s[i-1])^k) {
              if(j+(1-l) < 2) chmin(dp[i+1][j+(1-l)][l], dp[i][j][k]+(l ? C[i] : 0));
            } else {
              if(j+l < 2) chmin(dp[i+1][j+l][l], dp[i][j][k]+(l ? C[i] : 0));
            }
          }
        }
      }
    }
  }
  cout << *min_element(all(dp[n][1])) << endk;
  return 0;
}
