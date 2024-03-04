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
  int a, b; cin >> a >> b;
  ld ok = 1, ng = 1500;
  auto test = [&](ld l) -> bool {
    if(acos(min((ld)1, b/l)) > M_PI/6) return false;
    return (sin(acos(min((ld)1, b/l)) + M_PI/3) <= a/l);
  };
  rep(_, 100) {
    ld mid = (ok+ng)/2;
    (test(mid) ? ok : ng) = mid;
  }
  cout << fixed << setprecision(20) << ok << endk;
  return 0;
}
