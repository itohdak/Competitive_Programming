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
  int h, w; cin >> h >> w;
  vector<vector<ll>> A(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, h-1) rep(j, w-1) {
    if(i == h-2 && j == w-2) {
      vector<int> tmp;
      rep(x, 2) rep(y, 2) tmp.push_back(A[i+x][j+y]);
      sort(all(tmp));
      rep(x, 2) rep(y, 2) A[i+x][j+y] -= tmp[1];
    } else {
      ll tmp = A[i][j];
      rep(x, 2) rep(y, 2) A[i+x][j+y] -= tmp;
    }
  }
  ll ans = 0;
  rep(i, h) rep(j, w) ans += abs(A[i][j]);
  cout << ans << endk;
  rep(i, h) {
    rep(j, w) {
      cout << A[i][j] << ' ';
    }
    cout << endk;
  }
  return 0;
}
