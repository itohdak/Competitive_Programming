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
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> rem(m); rep(i, n) rem[A[i]%m]++;
  int ans = 0;
  ans += (rem[0] ? 1 : 0);
  for(int i=1; i<=(m-1)/2; i++) {
    int mn = min(rem[i], rem[m-i]);
    int mx = max(rem[i], rem[m-i]);
    if(mx > mn+1) {
      ans += 1 + mx - (mn+1);
    } else {
      ans += (mx+mn ? 1 : 0);
    }
  }
  if(m % 2 == 0) ans += (rem[m/2] ? 1 : 0);
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
