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

void solve() {
  ll n2, n3, n4; cin >> n2 >> n3 >> n4;
  ll n6 = n3/2;
  ll ans = 0;
  ll tmp = 0;
  {
    tmp = min(n6, n4);
    ans += tmp;
    n6 -= tmp;
    n4 -= tmp;
  }
  if(n6) {
    tmp = min(n6, n2/2);
    ans += tmp;
    n6 -= tmp;
    n2 -= 2*tmp;
  }
  if(n4) {
    tmp = min(n4/2, n2);
    ans += tmp;
    n4 -= 2*tmp;
    n2 -= tmp;
  }
  if(n4) {
    tmp = min(n4, n2/3);
    ans += tmp;
    n4 -= tmp;
    n2 -= 3*tmp;
  }
  if(n2) {
    tmp = n2/5;
    ans += tmp;
    n2 -= 5*tmp;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
