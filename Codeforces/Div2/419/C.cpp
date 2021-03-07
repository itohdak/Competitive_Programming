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
  vector<vector<int>> B(n, vector<int>(m));
  rep(i, n) rep(j, m) {
    cin >> A[i][j];
    B[i][j] = A[i][j];
  }
  vector<int> rows, cols;
  if(m >= n) {
    rep(i, n) {
      int mn = *min_element(all(B[i]));
      rep(j, mn) rows.push_back(i);
      rep(j, m) B[i][j] -= mn;
    }
    rep(j, m) {
      int mn = inf, mx = 0;
      rep(i, n) {
        chmin(mn, B[i][j]);
        chmax(mx, B[i][j]);
      }
      // assert(mn >= 0);
      if(mx != mn) {
        cout << -1 << endk;
        return 0;
      }
      rep(i, mn) cols.push_back(j);
      rep(i, n) B[i][j] -= mn;
    }
    rep(i, n) rep(j, m) {
      assert(B[i][j] == 0);
    }
    cout << rows.size() + cols.size() << endk;
    for(int i: rows) cout << "row " << i+1 << endk;
    for(int i: cols) cout << "col " << i+1 << endk;
  } else {
    rep(j, m) {
      int mn = inf, mx = 0;
      rep(i, n) {
        chmin(mn, B[i][j]);
        chmax(mx, B[i][j]);
      }
      // if(mx != mn) {
      //   cout << -1 << endk;
      //   return 0;
      // }
      rep(i, mn) cols.push_back(j);
      rep(i, n) B[i][j] -= mn;
    }
    rep(i, n) {
      int mn = *min_element(all(B[i]));
      int mx = *max_element(all(B[i]));
      if(mx != mn) {
        cout << -1 << endk;
        return 0;
      }
      rep(j, mn) rows.push_back(i);
      rep(j, m) B[i][j] -= mn;
    }
    rep(i, n) rep(j, m) {
      assert(B[i][j] == 0);
    }
    cout << rows.size() + cols.size() << endk;
    for(int i: rows) cout << "row " << i+1 << endk;
    for(int i: cols) cout << "col " << i+1 << endk;
  }
  return 0;
}
