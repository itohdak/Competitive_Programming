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

int D[11][11][11][11][11][11];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 11) D[i][j][k][l][m][n] = 0;
  rep(i, n) {
    vector<int> d;
    int tmp = A[i];
    rep(j, 6) {
      d.push_back(tmp%10);
      tmp /= 10;
    }
    D[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]]++;
  }
  rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 10) D[i][j][k][l][m][n+1] += D[i][j][k][l][m][n];
  rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 10) D[i][j][k][l][n+1][m] += D[i][j][k][l][n][m];
  rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 10) D[i][j][k][n+1][l][m] += D[i][j][k][n][l][m];
  rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 10) D[i][j][n+1][k][l][m] += D[i][j][n][k][l][m];
  rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 10) D[i][n+1][j][k][l][m] += D[i][n][j][k][l][m];
  rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 10) D[n+1][i][j][k][l][m] += D[n][i][j][k][l][m];
  ll ans = 0;
  rep(i, n) {
    vector<int> d;
    int tmp = A[i];
    rep(j, 6) {
      d.push_back(tmp%10);
      tmp /= 10;
    }
    bool ok = true;
    rep(j, 6) if(d[j]*2 >= 10) ok = false;
    ans += D[9-d[0]][9-d[1]][9-d[2]][9-d[3]][9-d[4]][9-d[5]]-ok;
  }
  cout << ans/2 << endk;
  return 0;
}
