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
  vector<vector<int>> A(n, vector<int>(n, -1));
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  int x = 0, y = 0;
  int d = 0;
  rep(i, n*n-1) {
    A[x][y] = i+1;
    int nx = x+dx[d];
    int ny = y+dy[d];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n || A[nx][ny] != -1) {
      d = (d+1)%4;
    }
    x += dx[d];
    y += dy[d];
  }
  rep(i, n) {
    rep(j, n) {
      if(i == n/2 && j == n/2) cout << "T ";
      else cout << A[i][j] << ' ';
    }
    cout << endk;
  }
  return 0;
}
