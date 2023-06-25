#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int h, c, t;
  cin >> h >> c >> t;
  int d = h-c;
  if(d-2*(h-t) == 0) {
    cout << 2 << endl;
    return;
  }
  int n = max(0, (h-t)/(d-2*(h-t)));
  auto f = [&](int n) {
    return h - (long double)n/(2*n+1)*d;
  };
  long double mid = (long double)(h+c)/2;
  if(abs(f(n)-t) <= abs(f(n+1)-t)) {
    if(abs(mid-t) < abs(f(n)-t)) {
      cout << 2 << endl;
    } else if(abs(mid-t) == abs(f(n)-t)) {
      cout << min(2*n+1, 2) << endl;
    } else {
      cout << 2*n+1 << endl;
    }
  } else {
    if(abs(mid-t) <= abs(f(n+1)-t)) {
      cout << 2 << endl;
    } else {
      cout << 2*(n+1)+1 << endl;
    }
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
