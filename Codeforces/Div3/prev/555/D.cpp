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
  ll n, k; cin >> n >> k;
  vector<ll> ans(k);
  ll rem = n;
  rep(i, k) {
    // mn: (2*x+k-i-1)*(k-i)/2 <= rem
    ans[i] = min((rem*2/(k-i)-(k-i-1))/2, (i ? ans[i-1]*2 : longinf));
    if(ans[i] <= (i ? ans[i-1] : 0)) {
      cout << "NO" << endk;
      return;
    }
    rem -= ans[i];
  }
  if(accumulate(all(ans), 0LL) != n) {
    cout << "NO" << endk;
    return;
  }
  cout << "YES" << endk;
  rep(i, k) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
