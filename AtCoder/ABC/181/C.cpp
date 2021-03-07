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
  vector<ll> X(n), Y(n);
  rep(i, n) cin >> X[i] >> Y[i];
  rep(i, n) REP(j, i+1, n) REP(k, j+1, n) {
    ll dx1 = X[j] - X[i], dy1 = Y[j] - Y[i];
    ll dx2 = X[k] - X[i], dy2 = Y[k] - Y[i];
    if(dx1 * dy2 == dy1 * dx2) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
