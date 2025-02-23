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
  int r; cin >> r;
  ll ans = 1;
  for(int i=1; i<=r; i++) {
    // r*r >= (i+0.5)*(i+0.5) + (mx+0.5)*(mx+0.5)
    // 4*r*r >= (2*i+1)*(2*i+1) + (2*mx+1)*(2*mx+1)
    ll mx = max(0LL, (ll)ceil((sqrtl(1LL*4*r*r - 1LL*(2*i+1)*(2*i+1))-1)/2));
    ans += 4*mx;
  }
  cout << ans << endk;
  return 0;
}
