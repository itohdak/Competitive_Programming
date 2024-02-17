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
  ll n, m, k; cin >> n >> m >> k;
  ll gcd = __gcd(n, m);
  ll lcm = n/gcd*m;
  auto test = [&](ll t) -> bool {
    ll cnt = t/n + t/m - t/lcm*2;
    return cnt >= k;
  };
  ll ok = longinf, ng = 0;
  while(ok-ng > 1) {
    ll mid = (ok+ng)/2;
    (test(mid) ? ok : ng) = mid;
  }
  cout << ok << endk;
  return 0;
}
