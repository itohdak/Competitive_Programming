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
  ll n, k; cin >> n >> k;
  if(2*n < log2(3*k+1)) {
    cout << "NO" << endk;
  } else {
    int tmp = log2(k);
    while(tmp <= n && pow(2, tmp+1) - (tmp+1) - 1 <= k) tmp++;
    int tmpk = n - tmp + 1;
    auto f = [&](ll n) {
      return (pow(4, n)-1)/3;
    };
    ld ub = f(n-tmpk) + pow(pow(2, n-tmpk)-1, 2)*f(tmpk);
    if(k <= ub) {
      cout << "YES" << ' ' << tmpk << endk;
    } else {
      cout << "NO" << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
