#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  ll x, y, a, b; cin >> x >> y >> a >> b;
  if(a == b) {
    cout << min(x/a, y/a) << endk;
    return;
  }
  ll m = (x*a-y*b)/(a*a-b*b);
  ll ans = 0;
  for(ll i=m-2; i<=m+2; i++) {
    if(i < 0) {
      chmax(ans, min(x/b, y/a));
      continue;
    }
    ll remx = x - a * i;
    ll remy = y - b * i;
    if(remx < 0 || remy < 0) {
      chmax(ans, min(x/a, y/b));
      continue;
    }
    chmax(ans, i+min(remx/b, remy/a));
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
