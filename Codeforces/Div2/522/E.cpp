#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  vector<vector<vector<bool>>> dpl(n+1, vector<vector<bool>>(n+1, vector<bool>(10001)));
  dpl[0][0][0] = 1;
  rep(i, n) {
    rep(j, n+1) {
      rep(k, 10001) {
        if(!dpl[i][j][k]) continue;
        dpl[i+1][j][k] = true;
        if(j+1 < n+1) dpl[i+1][j+1][k+A[i]] = true;
      }
    }
  }
  vector<vector<vector<bool>>> dpr(n+1, vector<vector<bool>>(n+1, vector<bool>(10001)));
  dpr[n][0][0] = 1;
  for(int i=n; i>0; i--) {
    rep(j, n+1) {
      rep(k, 10001) {
        if(!dpr[i][j][k]) continue;
        dpr[i-1][j][k] = true;
        if(j+1 < n+1) dpr[i-1][j+1][k+A[i-1]] = true;
      }
    }
  }
  int ans = 0;
  int l = 0, r = 0;
  while(l < n) {
    r = l;
    while(r < n && A[r] == A[l]) r++;
    for(int i=1; i<=r-l; i++) {
      bool ok = true;
      for(int j=0; j<=A[l]*i; j++) {
        for(int k=0; k<=i; k++) {
          if(dpl[l][k][j] && dpr[r][i-k][A[l]*i-j]) {
            ok = false;
            break;
          }
        }
        if(!ok) break;
      }
      if(!ok) break;
      chmax(ans, i);
    }
    l = r;
  }
  cout << ans << endk;
  return 0;
}
