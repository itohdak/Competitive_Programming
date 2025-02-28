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
  vector<ll> L(n), R(n);
  vector<pair<ll, ll>> P(n);
  rep(i, n) {
    cin >> L[i] >> R[i];
    P[i] = {L[i], R[i]};
  }
  sort(all(L));
  sort(all(R));
  int ans = n;
  rep(i, n) {
    auto [l, r] = P[i];
    int cnt = 0;
    cnt += end(L) - lower_bound(all(L), r+1);
    cnt += upper_bound(all(R), l-1) - begin(R);
    chmin(ans, cnt);
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
