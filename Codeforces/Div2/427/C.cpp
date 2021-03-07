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
  int n, q, c; cin >> n >> q >> c;
  vector<int> X(n), Y(n), S(n);
  vector<vector<vector<int>>> sum(c+1, vector<vector<int>>(105, vector<int>(105)));
  rep(i, n) {
    cin >> X[i] >> Y[i] >> S[i];
    rep(j, c+1) sum[j][X[i]][Y[i]] += (S[i]+j)%(c+1);
  }
  rep(j, c+1) {
    rep(x, 105) rep(y, 104) {
      sum[j][x][y+1] += sum[j][x][y];
    }
    rep(y, 105) rep(x, 104) {
      sum[j][x+1][y] += sum[j][x][y];
    }
  }
  rep(i, q) {
    ll t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    int m = t%(c+1);
    cout << sum[m][x2][y2] - sum[m][x1-1][y2] - sum[m][x2][y1-1] + sum[m][x1-1][y1-1] << endk;
  }
  return 0;
}
