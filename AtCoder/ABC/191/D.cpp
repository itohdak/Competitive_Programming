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
  ld xd, yd, rd;
  cin >> xd >> yd >> rd;
  ll x, y, r;
  x = round(xd*10000), y = round(yd*10000), r = round(rd*10000);
  auto bsearch = [&](ll d) {
    ll ok = 0, ng = 5e9;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (mid*mid<=d ? ok : ng) = mid;
    }
    return ok;
  };
  ll ans = 0;
  int bi = ((x-r)/10000-5)*10000;
  int ei = ((x+r)/10000+5)*10000;
  for(ll i=bi; i<=ei; i+=10000) {
    ll D = (r*r-(i-x)*(i-x));
    if(D < 0) continue;
    ll rt = bsearch(D);
    ll lb = (y-rt<0 ? (y-rt)/10000 : (y-rt+9999)/10000);
    ll ub = (y+rt<0 ? (y+rt-9999)/10000 : (y+rt)/10000);
    ans += ub-lb+1;
  }
  cout << ans << endk;
  return 0;
}
