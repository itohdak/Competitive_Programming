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
  int n; ll k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  ll mex = n;
  rep(i, n) {
    if(A[i] != i) {
      mex = i;
      break;
    }
  }
  if(mex > A[n-1]) {
    cout << n+k << endk;
  } else {
    ll val = (A[n-1]+mex+1)/2;
    if(k == 0) cout << n << endk;
    else if(*lower_bound(all(A), val) == val) cout << n << endk;
    else cout << n+1 << endk;
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
