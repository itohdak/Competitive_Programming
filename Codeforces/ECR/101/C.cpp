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
  ll n, k; cin >> n >> k;
  vector<ll> H(n); rep(i, n) cin >> H[i];
  ll mn, mx;
  rep(i, n) {
    if(i == 0) {
      mn = mx = H[0];
    } else {
      mn = max(H[i], mn-k+1);
      mx = min(H[i]+k-1, mx+k-1);
      if(mn > mx) {
        cout << "NO" << endk;
        return;
      }
    }
    if(i == n-1) {
      if(mn <= H[i] && H[i] <= mx) cout << "YES" << endk;
      else cout << "NO" << endk;
    }
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
