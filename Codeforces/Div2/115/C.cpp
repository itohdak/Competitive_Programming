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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll sum = accumulate(all(A), 0LL);
  // n : sum == n-2 : sum2 == 2 * d
  if(sum*2%n) cout << 0 << endk;
  else {
    ll d = sum*2/n;
    map<ll, int> cnt;
    rep(i, n) cnt[A[i]]++;
    ll ans = 0;
    for(auto [v, c]: cnt) {
      ll u = d-v;
      if(!cnt.count(u)) continue;
      if(v == u) ans += 1LL*c*(c-1);
      else ans += 1LL*c*cnt[u];
    }
    assert(ans%2 == 0);
    cout << ans/2 << endk;
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
