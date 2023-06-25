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
  int n; cin >> n;
  vector<ll> C(n); rep(i, n) cin >> C[i];
  ll mn1 = C[0], mn2 = C[1];
  ll sum1 = C[0], sum2 = C[1];
  int cnt1 = 1, cnt2 = 1;
  ll ans = (C[0]+C[1])*n;
  for(int i=2; i<n; i++) {
    if(i%2) {
      sum2 += C[i];
      chmin(mn2, C[i]);
      cnt2++;
    } else {
      sum1 += C[i];
      chmin(mn1, C[i]);
      cnt1++;
    }
    ll tmp = mn2 * (n-cnt2+1) + (sum2-mn2) + mn1 * (n-cnt1+1) + (sum1-mn1);
    chmin(ans, tmp);
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
