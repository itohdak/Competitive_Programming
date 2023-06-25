#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  ll a, b;
  cin >> a >> b;
  ll x_ = (2*a-b)/3;
  ll y_ = (2*b-a)/3;
  // cout << x_ << ' ' << y_ << endl;
  if(x_ < 0) {
    cout << min(a, b/2) << endl;
  } else if(y_ < 0) {
    cout << min(b, a/2) << endl;
  } else {
    ll ans = 0;
    for(int i=-2; i<=2; i++) {
      for(int j=-2; j<=2; j++) {
        ll x = x_+i, y = y_+j;
        if(x < 0 || y < 0) continue;
        if(2*x+y > a || x+2*y > b) continue;
        ans = max(x+y, ans);
      }
    }
    cout << ans << endl;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
