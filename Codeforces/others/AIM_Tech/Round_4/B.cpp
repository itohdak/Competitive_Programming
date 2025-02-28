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
  int n, m; cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  vector<ll> pw(55);
  pw[0] = 1;
  rep(i, 54) pw[i+1] = pw[i]*2;
  ll ans = 0;
  rep(i, n) {
    int cnt = 0;
    rep(j, m) cnt += A[i][j];
    ans += pw[cnt]-1-cnt;
    ans += pw[m-cnt]-1-(m-cnt);
  }
  rep(j, m) {
    int cnt = 0;
    rep(i, n) cnt += A[i][j];
    ans += pw[cnt]-1-cnt;
    ans += pw[n-cnt]-1-(n-cnt);
  }
  ans += 1LL*n*m;
  cout << ans << endk;
  return 0;
}
