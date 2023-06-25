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
  int n; cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  ll ans = 0;
  rep(d, 30) {
    vector<ll> _A(n), _B(n);
    ll mask = ((1LL<<(d+1))-1);
    rep(i, n) {
      _A[i] = A[i] & mask;
      _B[i] = B[i] & mask;
    }
    sort(all(_B));
    ll cnt = 0;
    ll stride = (1LL<<d);
    for(ll a: _A) {
      cnt += upper_bound(all(_B), 2*stride-a-1) - lower_bound(all(_B), 1*stride-a);
      cnt += upper_bound(all(_B), 4*stride-a-1) - lower_bound(all(_B), 3*stride-a);
    }
    if(cnt&1) ans ^= stride;
  }
  cout << ans << endk;
  return 0;
}
