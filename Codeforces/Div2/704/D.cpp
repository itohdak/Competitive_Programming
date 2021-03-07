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
  int a, b, k; cin >> a >> b >> k;
  if(k == 0) {
    cout << "Yes" << endk;
    string x = string(b, '1') + string(a, '0');
    cout << x << endk << x << endk;
    return;
  }
  if(a < 1 || b < 2) {
    cout << "No" << endk;
    return;
  }
  if(a+b < k+2) {
    cout << "No" << endk;
    return;
  }
  cout << "Yes" << endk;
  int n = a+b;
  string x(n, ' '), y(n, ' ');
  x[0] = y[0] = '1';
  x[1] = '1', y[1] = '0';
  x[1+k] = '0', y[1+k] = '1';
  a--, b -= 2;
  rep(i, n) {
    if(x[i] == ' ') {
      if(b) {
        x[i] = y[i] = '1';
        b--;
      } else {
        assert(a > 0);
        x[i] = y[i] = '0';
        a--;
      }
    }
  }
  assert(a == 0 && b == 0);
  cout << x << endk << y << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
