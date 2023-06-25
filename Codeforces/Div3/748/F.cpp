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

tuple<int, int, int> dp[41][40][40][41];
void solve() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  rep(i, n+1) rep(j, a) rep(k, b) rep(l, n+1) dp[i][j][k][l] = {-1, -1, -1};
  rep(i, n) rep(j, a) rep(k, b) rep(l, n+1) {
    if(i == 0 && (j || k || l)) continue;
    if(i && dp[i][j][k][l] == make_tuple(-1, -1, -1)) continue;
    int cur = s[i]-'0';
    dp[i+1][(j*10+cur)%a][k][l+1] = {j, k, l};
    dp[i+1][j][(k*10+cur)%b][l] = {j, k, l};
  }
  int tmp = inf;
  int st = -1;
  REP(i, 1, n) {
    if(dp[n][0][0][i] != make_tuple(-1, -1, -1)) {
      if(tmp > abs(i-(n-i))) {
        tmp = abs(i-(n-i));
        st = i;
      }
    }
  }
  if(tmp == inf) cout << -1 << endk;
  else {
    string ans;
    int j = 0, k = 0, l = st;
    for(int i=n; i>0; i--) {
      auto [nj, nk, nl] = dp[i][j][k][l];
      ans += (nl == l ? 'B' : 'R');
      j = nj, k = nk, l = nl;
    }
    reverse(all(ans));
    cout << ans << endk;
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
