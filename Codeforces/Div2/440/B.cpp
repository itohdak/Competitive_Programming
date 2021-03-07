#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  if(k == 1) {
    cout << *min_element(all(A)) << endk;
  } else if(k == 2) {
    vector<ll> minL(n+1, longinf), minR(n+1, longinf);
    rep(i, n) minL[i+1] = min(minL[i], A[i]);
    rrep(i, n) minR[i] = min(minR[i+1], A[i]);
    ll ans = -longinf;
    REP(i, 1, n) {
      chmax(ans, max(minL[i], minR[i]));
    }
    cout << ans << endk;
  } else {
    cout << *max_element(all(A)) << endk;
  }
  return 0;
}
