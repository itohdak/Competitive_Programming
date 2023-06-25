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
  vector<ll> B(n); rep(i, n) cin >> B[i];
  ll sum = 0;
  rep(i, n) sum += A[i]*B[i];
  ll ans = sum;
  rep(c, n) { // 2
    ll tmp = sum;
    rep(l, n) {
      if(c-l < 0 || c+1+l >= n) break;
      // cout << c-l << ' ' << c+1+l << endk;
      tmp -= A[c-l]*B[c-l] + A[c+1+l]*B[c+1+l];
      tmp += A[c-l]*B[c+1+l] + A[c+1+l]*B[c-l];
      chmax(ans, tmp);
    }
  }
  rep(c, n) { // 3
    ll tmp = sum;
    rep(l, n) {
      if(c-1-l < 0 || c+1+l >= n) break;
      // cout << c-1-l << ' ' << c+1+l << endk;
      tmp -= A[c-1-l]*B[c-1-l] + A[c+1+l]*B[c+1+l];
      tmp += A[c-1-l]*B[c+1+l] + A[c+1+l]*B[c-1-l];
      chmax(ans, tmp);
    }
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
