#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
  int n, k, x; cin >> n >> k >> x;
  if(x == 1) {
    if(k == 1) {
      cout << "NO" << endk;
    } else if(k == 2) {
      if(n % 2 == 0) {
	cout << "YES" << endk;
	cout << n/2 << endk;
	rep(i, n/2) cout << 2 << ' ';
	cout << endk;
      } else {
	cout << "NO" << endk;
      }
    } else {
      if(n % 2 == 0) {
	cout << "YES" << endk;
	cout << n/2 << endk;
	rep(i, n/2) cout << 2 << ' ';
	cout << endk;
      } else {
	cout << "YES" << endk;
	cout << n/2 << endk;
	cout << 3 << ' ';
	rep(i, (n-3)/2) cout << 2 << ' ';
	cout << endk;
      }
    }
  } else {
    cout << "YES" << endk;
    cout << n << endk;
    rep(i, n) cout << 1 << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
