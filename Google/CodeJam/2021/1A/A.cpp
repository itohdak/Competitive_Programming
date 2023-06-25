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
  int n; cin >> n;
  vector<ll> X(n); rep(i, n) cin >> X[i];
  ll ans = 0;
  rep(i, n) {
    if(i) {
      if(X[i] > X[i-1]) continue;
      ll prev = X[i-1]+1;
      int d1 = log10(prev)+1;
      int d2 = log10(X[i])+1;
      ll pw = 1;
      rep(j, d1-d2) {
        prev /= 10;
        pw *= 10;
      }
      if(prev < X[i]) {
        X[i] *= pw;
        ans += d1-d2;
      } else if(prev == X[i]) {
        X[i] = X[i-1]+1;
        ans += d1-d2;
      } else {
        X[i] *= pw * 10;
        ans += d1-d2+1;
      }
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
