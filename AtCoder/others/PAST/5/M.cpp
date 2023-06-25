#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  int n; ll l; cin >> n >> l;
  vector<ll> A(n+1); rep(i, n) cin >> A[i+1];
  rep(i, n+1) if(i) A[i] += A[i-1];
  auto test = [&](ll m) -> bool {
    vector<int> dp(n+2);
    // cout << "===" << endk;
    // cout << m << ' ' << l << ' ' << A << endk;
    rep(i, n+1) {
      if(i) dp[i] += dp[i-1];
      if(i == 0 || dp[i]) {
        int lb = lower_bound(all(A), A[i]+m) - begin(A);
        int ub = upper_bound(all(A), A[i]+l) - begin(A);
        dp[lb]++;
        dp[ub]--;
      }
      // cout << dp << endk;
    }
    return dp[n] > 0;
  };
  auto bsearch = [&]() {
    ll ok = 0, ng = l+1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
