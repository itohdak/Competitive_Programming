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

void solve() {
  int n; cin >> n;
  vector<vector<int>> A(2*n, vector<int>(2*n));
  int sum = 0;
  rep(i, n) {
    string s; cin >> s;
    rep(j, n) {
      A[i+n][j] = A[i][j+n] = A[i+n][j+n] = A[i][j] = s[j]-'0';
      sum += A[i][j];
    }
  }
  int ans = n*n;
  int m = 0;
  rep(i, n) {
    int x = 0, y = i;
    int cnt = 0;
    rep(j, n) {
      cnt += A[x][y];
      x++;
      y++;
    }
    chmin(ans, (n-cnt)+(sum-cnt));
    m++;
    while(x < 2*n && y < 2*n) {
      cnt -= A[x-n][y-n];
      cnt += A[x][y];
      x++;
      y++;
      chmin(ans, (n-cnt)+(sum-cnt));
      m++;
    }
  }
  rep(i, n) {
    if(i == 0) continue;
    int x = i, y = 0;
    int cnt = 0;
    rep(j, n) {
      cnt += A[x][y];
      x++;
      y++;
    }
    chmin(ans, (n-cnt)+(sum-cnt));
    m++;
    while(x < 2*n && y < 2*n) {
      cnt -= A[x-n][y-n];
      cnt += A[x][y];
      x++;
      y++;
      chmin(ans, (n-cnt)+(sum-cnt));
      m++;
    }
  }
  cout << ans << endk;
  // cout << m << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
