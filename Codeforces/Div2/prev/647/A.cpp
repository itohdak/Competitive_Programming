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
  ll mx = max(a, b);
  ll mn = min(a, b);
  ll cnt = 0;
  while(mx >= mn * 2) {
    mn *= 2;
    cnt++;
  }
  if(mx == mn) {
    // cout << cnt << endl;
    ll ans = 0;
    for(int i=3; i>=1; i--) {
      ll tmp = cnt / i;
      ans += tmp;
      cnt -= tmp * i;
    }
    cout << ans << endl;
  } else {
    cout << -1 << endl;
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
