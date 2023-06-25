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
  ll n, s, t, a, b;
  cin >> n >> s >> t >> a >> b;
  s--; t--;
  auto calc = [&](int i) -> ld {
    assert(0 <= i && i <= t);
    if(i <= s && s <= t) {
      return a*(t-i);
    } else {
      // sum == (b+sum/n)*(n-1-t+i) + a*(t-i)*(t-i+1)/2
      // (t-i+1)/n*sum == b*(n-1-t+i) + a*(t-i)*(t-i+1)/2
      ld sum = ((ld)b*(n-1-t+i) + (ld)a*(t-i)*(t-i+1)/2) * n/(t-i+1);
      return b+sum/n;
    }
  };
  auto bsearch = [&]() {
    auto test = [&](ll k) -> bool {
      return calc(k) <= calc(k+1);
    };
    ll ok = t, ng = -1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll ret = bsearch();
  cout << fixed << setprecision(10) << calc(ret) << endk;
  return 0;
}
