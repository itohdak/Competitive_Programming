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
  ll n, m; cin >> n >> m;
  if(n > m) swap(n, m);
  if(n == 1) {
    cout << m/6*6 + 2*max(m%6-3, 0LL) << endk;
  } else if(n == 2) {
    if(m == 2) cout << 0 << endk;
    else if(m == 3) cout << 4 << endk;
    else if(m == 7) cout << 12 << endk;
    else cout << n*m << endk;
  } else {
    cout << n*m - (n%2 && m%2) << endk;
  }
  return 0;
}
