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
  sort(all(A));
  ll sum = accumulate(all(A), 0LL);
  int m; cin >> m;
  while(m--) {
    ll x, y; cin >> x >> y;
    int i = lower_bound(all(A), x) - begin(A);
    if(i == n) {
      cout << max(0LL, x-A[i-1])+max(0LL, y-(sum-A[i-1])) << endk;
    } else {
      ll cost = LONG_LONG_MAX;
      chmin(cost, max(0LL, y-(sum-A[i])));
      if(i > 0) chmin(cost, max(0LL, x-A[i-1])+max(0LL, y-(sum-A[i-1])));
      cout << cost << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
