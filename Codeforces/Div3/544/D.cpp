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
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  map<pair<ll, ll>, int> mp;
  rep(i, n) {
    if(A[i] == 0 && B[i] == 0) {
      mp[{0, 0}]++;
    } else if(A[i] == 0) {
      // mp[{0, 1}]++;
    } else {
      if(A[i] < 0) {
        A[i] *= -1;
        B[i] *= -1;
      }
      ll g = __gcd(A[i], B[i]);
      pair<ll, ll> p = {A[i]/g, B[i]/g};
      mp[p]++;
    }
  }
  int ans = 0;
  int zero = 0;
  for(auto [p, c]: mp) {
    if(p.first == 0 && p.second == 0) {
      zero = c;
      continue;
    }
    chmax(ans, c);
  }
  cout << ans+zero << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
