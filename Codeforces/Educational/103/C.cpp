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
  vector<ll> C(n); rep(i, n) cin >> C[i];
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(n); rep(i, n) cin >> B[i];
  rep(i, n) if(A[i] > B[i]) swap(A[i], B[i]);
  ll mx = 0;
  ll ans = 0;
  mx = B[1]-A[1];
  rep(i, n) {
    if(i) {
      mx += 2;
      chmax(ans, mx+C[i]-1);
      if(i+1 < n) {
        mx = max(mx+(C[i]-1)-(B[i+1]-A[i+1]), (B[i+1]-A[i+1]));
        if(B[i+1] == A[i+1]) mx = 0;
      }
    }
  }
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
