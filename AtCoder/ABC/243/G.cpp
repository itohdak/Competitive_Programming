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

#define sz 60000
ll val[sz] = {0};
ll sum[sz] = {0};
void solve() {
  ll x; cin >> x;
  ll ans = 0;
  // auto sqrt = [](ll x) -> ll {
  //   ll ok = 1, ng = 3000000001LL;
  //   while(ng-ok>1) {
  //     ll mid = (ok+ng)/2;
  //     (mid*mid<=x ? ok : ng) = mid;
  //   }
  //   return ok;
  // };
  // ll ub = sqrt(sqrt(x));
  ll ub = sqrtl(floorl(sqrtl((ld)x)));
  ll sqrtx = sqrtl((ld)x);
  for(ll i=1; i<=ub; i++) {
    ans += (sqrtx-i*i+1) * val[i];
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  val[1] = sum[1] = 1;
  for(int i=2; i<sz; i++) {
    int ub = sqrt(i);
    val[i] = sum[ub];
    sum[i] = sum[i-1] + val[i];
  }
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
