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
  int t; cin >> t;
  rep(_, t) {
    unsigned ll n, x, k; cin >> n >> x >> k;
    unsigned ll ans = 0;
    unsigned ll tmp = x;
    int prev = 0;
    auto count = [&](unsigned ll cur, unsigned ll d) -> unsigned ll {
      if(d > 64) return 0;
      rep(i, d) {
	if((cur<<i) > n+1) return 0;
      }
      return min(n+1, (cur+1)<<d) - min(n+1, cur<<d);
    };
    for(unsigned ll i=0; i<k+1; i++) {
      if(tmp == 0) break;
      if(i == 0) {
	ans += count(tmp, k);
      } else {
	if(k-i == 0) {
	  ans++;
	  break;
	}
	ans += count((tmp<<1)+(1-prev), k-i-1);
      }
      prev = tmp&1;
      tmp >>= 1;
    }
    cout << ans << endk;
  }
  return 0;
}
