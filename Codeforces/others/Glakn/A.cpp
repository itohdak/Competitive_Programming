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
  vector<int> A(n), B(n), C(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n) cin >> C[i];
  vector<int> ans(n);
  ans[0] = A[0];
  REP(i, 1, n-1) {
    if(A[i] != ans[i-1]) {
      ans[i] = A[i];
    } else if(B[i] != ans[i-1]) {
      ans[i] = B[i];
    } else if(C[i] != ans[i-1]) {
      ans[i] = C[i];
    }
  }
  if(A[n-1] != ans[n-2] && A[n-1] != ans[0]) ans[n-1] = A[n-1];
  else if(B[n-1] != ans[n-2] && B[n-1] != ans[0]) ans[n-1] = B[n-1];
  else if(C[n-1] != ans[n-2] && C[n-1] != ans[0]) ans[n-1] = C[n-1];
  rep(i, n) cout << ans[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
