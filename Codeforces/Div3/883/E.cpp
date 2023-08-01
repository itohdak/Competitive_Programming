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

set<ll> st;
void make() {
  for(ll k=2; k<=1000000; k++) {
    ll tmp = 1 + k + k*k + k*k*k;
    ll pw = k*k*k;
    while(1) {
      st.insert(tmp);
      if(pw >= LONG_LONG_MAX / k) break;
      pw *= k;
      if(tmp >= LONG_LONG_MAX - pw) break;
      tmp += pw;
    }
  }
}
void solve() {
  ll n; cin >> n;
  if(n < 7) cout << "NO" << endk;
  else {
    if(st.count(n)) {
      cout << "YES" << endk;
    } else {
      ll tmp = 4*n-3;
      ll rt = sqrt(tmp);
      if(rt*rt == tmp && (rt-1)%2 == 0) cout << "YES" << endk;
      else cout << "NO" << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
