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
  int n, m, K; cin >> n >> m >> K;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<vector<int>>> cnt(10, vector<vector<int>>(n+1, vector<int>(m+1)));
  rep(i, n) rep(j, m) {
    cnt[S[i][j]-'0'][i+1][j+1]++;
  }
  rep(k, 10) {
    rep(i, n) rep(j, m+1) {
      cnt[k][i+1][j] += cnt[k][i][j];
    }
    rep(j, m) rep(i, n+1) {
      cnt[k][i][j+1] += cnt[k][i][j];
    }
  }
  // rep(k, 10) {
  //   cout << "===" << endk;
  //   rep(i, n+1) cout << cnt[k][i] << endk;
  // }
  int ans = 1;
  for(int l=2; l<=min(n, m); l++) {
    rep(i, n) {
      if(i+l > n) break;
      rep(j, m) {
        if(j+l > m) break;
        rep(k, 10) {
          if(cnt[k][i+l][j+l]-cnt[k][i][j+l]-cnt[k][i+l][j]+cnt[k][i][j] >= l*l-K) chmax(ans, l);
        }
      }
    }
  }
  cout << ans << endk;
  return 0;
}
