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

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> X(n), Y(n);
  rep(i, n) cin >> X[i] >> Y[i];
  ll ans = X[0];
  ll cum = 0;
  ll b = 0;
  rep(i, n) {
    if(X[i] < 0 && b >= 0 && b+X[i]*Y[i] < 0) {
      ll tmp = b/abs(X[i]);
      if(tmp) chmax(ans, cum + b*tmp + X[i]*(tmp*(tmp+1)/2));
    }
    cum += b*Y[i] + X[i]*(Y[i]*(Y[i]+1)/2);
    b += X[i]*Y[i];
    chmax(ans, cum);
    // cout << cum << ' ' << b << endk;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
