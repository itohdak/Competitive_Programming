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
  int n, k; cin >> n >> k;
  vector<ll> E(n); rep(i, n) cin >> E[i];
  ll sum1 = 0;
  ll sum2 = 0;
  rep(i, n) {
    sum1 += E[i];
    sum2 += E[i]*E[i];
  }
  if(k == 1) {
    ll a = sum2 - sum1*sum1;
    ll b = 2 * sum1;
    if(a == 0 && b == 0) {
      cout << 1 << endk;
    } else if(abs(b) > 0 && a % b == 0) {
      cout << a/b << endk;
    } else {
      cout << "IMPOSSIBLE" << endk;
    }
  } else {
    ll a = 1-sum1;
    // ll sum1_new = sum1 + a;
    ll sum2_new = sum2 + a*a;
    if(sum2_new % 2) {
      ll b = (sum2_new-1)/2;
      cout << a << ' ' << b << endk;
      assert((sum1+a+b)*(sum1+a+b) == sum2+a*a+b*b);
    } else {
      cout << "IMPOSSIBLE" << endk;
    }
  }
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
