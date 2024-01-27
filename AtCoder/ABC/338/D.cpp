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
  int n, m; cin >> n >> m;
  vector<int> X(m);
  rep(i, m) {
    cin >> X[i];
    X[i]--;
  }
  vector<ll> cum(n+1);
  ll len = 0;
  rep(i, m-1) {
    int a = min(X[i], X[i+1]);
    int b = max(X[i], X[i+1]);
    int mn = min(n-(b-a), b-a);
    int mx = n-mn;
    int inc = mx-mn;
    len += mn;
    if(b-a == mn) {
      cum[a] += inc;
      cum[b] -= inc;
    } else {
      cum[b] += inc;
      cum[n] -= inc;
      cum[0] += inc;
      cum[a] -= inc;
    }
  }
  rep(i, n) {
    cum[i+1] += cum[i];
  }
  assert(cum[n] == 0);
  ll mn = longinf;
  rep(i, n) chmin(mn, cum[i]);
  cout << len+mn << endk;
  return 0;
}
