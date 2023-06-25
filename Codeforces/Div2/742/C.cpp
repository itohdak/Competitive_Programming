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
  ll n; cin >> n;
  vector<int> A;
  while(n) {
    A.push_back(n%10);
    n /= 10;
  }
  // reverse(all(A));
  int m = A.size();
  auto dp = [&](int mask) -> ll {
    mask <<= 2;
    vector<int> B(m);
    rep(i, m) {
      if((mask>>(i+2))&1) {
        if((mask>>i)&1) {
          B[i] = A[i]+10-1;
        } else {
          B[i] = A[i]+10;
        }
      } else {
        if((mask>>i)&1) {
          B[i] = A[i]-1;
        } else {
          B[i] = A[i];
        }
      }
      if(B[i] < 0) return 0LL;
    }
    // cout << (mask>>2) << ' ' << B << endk;
    ll ans = 1;
    rep(i, m) {
      ans *= min(9, B[i]) - max(0, B[i]-9) + 1;
    }
    return ans-(mask==0)*2;
  };
  ll ans = 0;
  rep(i, 1<<max(0, (m-2))) {
    ans += dp(i);
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
