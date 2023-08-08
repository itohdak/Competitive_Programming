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
  string x; cin >> x;
  reverse(all(x));
  int n = x.size();
  string y;
  int carry = 0;
  int p = -1;
  rep(i, n) {
    if(carry) {
      if(x[i]-'0' >= 4) {
	y += '0';
	p = i;
	carry = 1;
      } else {
	y += x[i]+1;
	carry = 0;
      }
    } else {
      if(x[i]-'0' >= 5) {
	y += '0';
	p = i;
	carry = 1;
      } else {
	y += x[i];
	carry = 0;
      }
    }
  }
  if(carry) y += '1';
  rep(i, p) y[i] = '0';
  reverse(all(y));
  cout << y << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
