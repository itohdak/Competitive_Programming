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
  ll n, m, s; cin >> n >> m >> s;
  vector<ll> A(n+2); rep(i, n) cin >> A[i+1];
  vector<ll> cum(n+3); rep(i, n+2) cum[i+1] = cum[i] + A[i];
  map<pair<int, ll>, ld> memo;
  auto solve = [&](auto solve, int r, ll s) -> ld {
    if(memo.count({r, s})) return memo[{r, s}];
    ld ans = 0;
    rep(i, r) {
      if(m*(r-i) >= s) {
        ld ave = (ld)1*s/(r-i);
        ll sum = cum[r+1]-cum[i+1];
        chmax(ans, ave*sum);
      } else {
        ll rem = s-m*(r-i);
        ll sum = cum[r+1]-cum[i+1];
        chmax(ans, m*sum + solve(solve, i, rem));
      }
    }
    // cout << r << ' ' << s << ' ' << ans << endk;
    return memo[{r, s}] = ans;
  };
  cout << fixed << setprecision(10) << solve(solve, n, s) << endk;
  return 0;
}
