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
  int n; ll k, x; cin >> n >> k >> x;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  vector<ll> v;
  int ans = 1;
  rep(i, n-1) {
    if(A[i+1]-A[i] > x) {
      v.push_back(A[i+1]-A[i]);
      ans++;
    }
  }
  sort(all(v));
  rep(i, v.size()) {
    if(k == 0) break;
    ll need = (v[i]-1)/x;
    if(need > k) break;
    k -= need;
    ans--;
  }
  cout << ans << endk;
  // auto bsearch = [&]() {
  //   auto test = [&](ll m) -> bool {
  //     return false;
  //   };
  //   ll ok = n, ng = 0;
  //   while(abs(ok-ng)>1) {
  //     ll mid = (ok+ng)/2;
  //     (test(mid) ? ok : ng) = mid;
  //   }
  //   return ok;
  // };
  // cout << bsearch() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
