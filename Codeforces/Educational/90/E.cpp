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
  ll n, k;
  cin >> n >> k;
  ll ans = LONG_LONG_MAX;
  if(2*n >= k*(k+1) && (2*n-k*(k+1))%(2*(k+1))==0) {
    ll d = (2*n-k*(k+1))/(2*(k+1));
    ll cur = 0;
    cur += min(d, 9-k);
    d -= cur;
    int i = 1;
    while(d > 0) {
      int tmp = min(d, 9LL);
      cur += (ll)pow(10, i) * tmp;
      d -= tmp;
      i++;
    }
    ans = min(cur, ans);
  }
  for(int m=1; m<k+1; m++) {
    for(int l=1; l<=20; l++) {
      ll lb = 9*(l-1)*m + (19-m)*m/2 + (k+1-m) + (k+1-m)*(k-m)/2;
      if(n < lb) continue;
      ll cur = (ll)pow(10, l)-m;
      ll rem = n-lb;
      if(rem%(k+1)==0) {
        ll d = rem/(k+1);
        cur += (ll)pow(10, l) * min(d, 8LL);
        d -= min(d, 8LL);
        int i = l+1;
        while(d > 0) {
          int tmp = min(d, 9LL);
          cur += (ll)pow(10, i) * tmp;
          d -= tmp;
          i++;
        }
        ans = min(cur, ans);
      }
    }
  }
  cout << (ans == LONG_LONG_MAX ? -1 : ans) << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
