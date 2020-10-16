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
  int l, r; ll m; cin >> l >> r >> m;
  ll mn = m-r+l, mx = m-l+r;
  for(int i=l; i<=r; i++) {
    if((m-l+r)/i >= (m-r+l+i-1)/i) {
      ll n = (m-l+r)/i;
      if(n == 0) continue;
      ll a = i;
      ll tmp = n*a-m; // -b+c
      ll b, c;
      if(tmp > 0) {
        c = r;
        b = r-tmp;
      } else {
        b = r;
        c = tmp+b;
      }
      // cout << n << "\n";
      cout << a << ' ' << b << ' ' << c << "\n";
      return;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
