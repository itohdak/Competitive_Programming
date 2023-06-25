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
  ll l, r; cin >> l >> r;
  vector<int> L(10), R(10);
  rep(i, 10) {
    L[i] = l%10;
    l /= 10;
  }
  rep(i, 10) {
    R[i] = r%10;
    r /= 10;
  }
  ll ans = 0;
  ll tmp = 0;
  rrep(i, 10) {
    if(i == 9) {
      ans += R[i] - L[i];
    } else {
      ans += tmp * 10 + R[i] - L[i];
    }
    tmp = tmp * 10 + R[i] - L[i];
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
