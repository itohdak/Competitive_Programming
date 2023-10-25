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
  ll x, y; cin >> x >> y;
  vector<int> P(n-1);
  vector<ll> T(n-1);
  rep(i, n-1) {
    cin >> P[i] >> T[i];
  }
  int m = 1;
  for(int i=1; i<=8; i++) {
    m *= i / gcd(m, i);
  }
  vector<ll> ans(m);
  rep(i, m) {
    ll t = i;
    t += x;
    rep(j, n-1) {
      t = (t+P[j]-1)/P[j]*P[j] + T[j];
    }
    t += y;
    ans[i] = t;
  }
  int q; cin >> q;
  rep(i, q) {
    ll a; cin >> a;
    cout << a/m*m+ans[a%m] << endk;
  }
  return 0;
}
