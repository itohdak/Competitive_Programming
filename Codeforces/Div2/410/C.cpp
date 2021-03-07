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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll gcd = A[0];
  rep(i, n) gcd = __gcd(gcd, A[i]);
  if(gcd > 1) {
    cout << "YES" << endk;
    cout << 0 << endk;
    return;
  }
  ll ans = 0;
  int l = 0, r = 0;
  int flag = 0;
  while(l < n) {
    r = l;
    while(r < n && A[r]%2 == flag) r++;
    if(flag) {
      ans += (r-l)/2;
      if((r-l)%2) ans += 2;
    }
    l = r;
    flag = 1-flag;
  }
  cout << "YES" << endk;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
