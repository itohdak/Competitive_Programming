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
  int n; cin >> n;
  ll a, w; cin >> a >> w;
  int k; cin >> k;
  if(k == n) {
    if(a-w-(n-1) < 0) {
      if(a-w < 0) {
        ll ww = w-a;
        cout << -(ww/n+ww%n) << endk;
      } else {

      }
    } else {
      cout << (a-w-(n-1))/n << endk;
    }
  } else {
    if(a-(k-1) < 0) {
      if(n-(k-1) > w) cout << ":(" << endk;
      else cout << -1 << endk;
    } else {
      cout << (a-(k-1))/k << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
