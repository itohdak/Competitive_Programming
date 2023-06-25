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
  vector<pair<ll, ll>> P(n);
  for(auto& [a, b]: P) cin >> a >> b;
  sort(all(P), [&](pair<ll, ll> p1, pair<ll, ll> p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
  });
  int l = 0, r = n-1;
  ll ans = 0;
  ll bought = 0;
  while(l <= r) {
    if(bought >= P[l].second) {
      ans += P[l].first;
      bought += P[l].first;
      P[l].first = 0;
      l++;
    } else {
      while(l < r && bought+P[r].first < P[l].second) {
        bought += P[r].first;
        ans += P[r].first * 2;
        P[r].first = 0;
        r--;
      }
      if(r == l) {
        ll buy = min(P[l].second-bought, P[l].first);
        ans += buy * 2;
        bought += buy;
        P[l].first -= buy;
        ans += P[l].first;
        bought += P[l].first;
        P[l].first = 0;
        l++;
      } else {
        assert(P[l].second-bought <= P[r].first);
        ll buy = P[l].second-bought;
        ans += buy * 2;
        bought += buy;
        P[r].first -= buy;
        if(P[r].first == 0) r--;
        ans += P[l].first;
        bought += P[l].first;
        P[l].first = 0;
        l++;
      }
    }
    // cout << P << ' ' << l << ' ' << r << ' ' << bought << ' ' << ans << endk;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
