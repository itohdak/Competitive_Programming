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
  int n, m; cin >> n >> m;
  vector<vector<ll>> A(n, vector<ll>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  ll ans = 0;
  auto cost = [&](vector<ll>& a) {
    sort(all(a));
    if(a.size() == 4) {
      ll m1 = a[1], m2 = a[2];
      ll tmp1 = 0, tmp2 = 0;
      rep(k, 4) {
        tmp1 += abs(a[k]-m1);
        tmp2 += abs(a[k]-m2);
      }
      return min(tmp1, tmp2);
    } else {
      return abs(a[1]-a[0]);
    }
  };
  rep(i, n/2) rep(j, m/2) {
    vector<ll> a = {A[i][j], A[i][m-1-j], A[n-1-i][j], A[n-1-i][m-1-j]};
    ans += cost(a);
  }
  if(n%2) {
    rep(j, m/2) {
      vector<ll> a = {A[n/2][j], A[n/2][m-1-j]};
      ans += cost(a);
    }
  }
  if(m%2) {
    rep(i, n/2) {
      vector<ll> a = {A[i][m/2], A[n-1-i][m/2]};
      ans += cost(a);
    }
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
