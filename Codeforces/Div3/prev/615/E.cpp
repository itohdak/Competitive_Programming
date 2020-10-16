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
  vector<vector<int>> A(n, vector<int>(m));
  rep(i, n) rep(j, m) {
    cin >> A[i][j];
    A[i][j]--;
  }
  int ans = 0;
  rep(j, m) {
    vector<int> cnt(n);
    rep(i, n) {
      if(A[i][j]%m == j && (A[i][j]-j)/m < n) cnt[(i-(A[i][j]-j)/m+n)%n]++;
    }
    int mn = inf;
    rep(i, n) {
      chmin(mn, n-cnt[i]+i);
    }
    ans += mn;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
