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
  ll n, k; cin >> n >> k;
  int mx = 20;
  vector<int> D(mx);
  ll tmp = n;
  rep(i, mx) {
    D[i] = tmp % 10;
    tmp /= 10;
  }
  reverse(all(D));
  vector<vector<map<ll, ll>>> dp(mx+1, vector<map<ll, ll>>(4));
  dp[0][0][1] = 1;
  rep(i, mx) {
    for(auto [prod, cnt]: dp[i][0]) {
      rep(j, 10) {
        if(j < D[i]) {
          if(prod * j > k) continue;
          if(j == 0) dp[i+1][1][1] += cnt;
          else dp[i+1][3][prod*j] += cnt;
        } else if(j == D[i]) {
          if(prod * j > k) continue;
          if(j == 0) dp[i+1][0][1] += cnt;
          else dp[i+1][2][prod*j] += cnt;
        }
      }
    }
    for(auto [prod, cnt]: dp[i][1]) {
      rep(j, 10) {
        if(prod * j > k) continue;
        if(j == 0) dp[i+1][1][1] += cnt;
        else dp[i+1][3][prod*j] += cnt;
      }
    }
    for(auto [prod, cnt]: dp[i][2]) {
      rep(j, 10) {
        if(prod * j > k) continue;
        if(j < D[i]) {
          dp[i+1][3][prod*j] += cnt;
        } else if(j == D[i]) {
          dp[i+1][2][prod*j] += cnt;
        }
      }
    }
    for(auto [prod, cnt]: dp[i][3]) {
      rep(j, 10) {
        if(prod * j > k) continue;
        dp[i+1][3][prod*j] += cnt;
      }
    }
  }
  // cout << D << endk;
  // cout << dp << endk;
  ll ans = 0;
  rep(i, 4) {
    for(auto [prod, cnt]: dp[mx][i]) {
      assert(prod <= k);
      ans += cnt;
    }
  }
  cout << ans-1 << endk;
  return 0;
}
