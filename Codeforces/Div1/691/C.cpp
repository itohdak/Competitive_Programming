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
  vector<vector<int>> A(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];
  string s; cin >> s;
  vector<int> col(n), row(n); // 列, 行の順番
  rep(i, n) col[i] = row[i] = i;
  int tmpC = 0, tmpR = 0;
  vector<int> idR(n), idC(n); // 1の場所
  rep(i, n) rep(j, n) {
    if(A[i][j] == 1) {
      idR[i] = j;
      idC[j] = i;
    }
  }
  rep(i, m) {
    if(s[i] == 'R') {
      tmpC = ((find(all(col), tmpC) - begin(col)) + n - 1) % n;
    } else if(s[i] == 'L') {
      tmpC = ((find(all(col), tmpC) - begin(col)) + 1) % n;
    } else if(s[i] == 'D') {
      tmpR = ((find(all(row), tmpR) - begin(row)) + n - 1) % n;
    } else if(s[i] == 'U') {
      tmpR = ((find(all(row), tmpR) - begin(row)) + 1) % n;
    } else if(s[i] == 'I') {
      // TODO: sort row
      sort(all(row), [&](int i, int j) {
        return (idR[i]+n-tmpR)%n < (idR[j]+n-tmpR)%n;
      });
      tmpR = 0;
    } else if(s[i] == 'C') {
      // TODO: sort col
      sort(all(col), [&](int i, int j) {
        return (idC[i]+n-tmpC)%n < (idC[j]+n-tmpC)%n;
      });
      tmpC = 0;
    } else {
      assert(false);
    }

    cout << row << endk;
    cout << col << endk;
    cout << tmpR << ' ' << tmpC << endk;
    int ib = find(all(col), tmpC) - begin(col);
    int jb = find(all(row), tmpR) - begin(row);
    rep(i, n) {
      rep(j, n) {
        cout << A[row[(ib+i)%n]][col[(jb+j)%n]] << ' ';
      }
      cout << endk;
    }
    cout << endk;

  }
  cout << col << endk;
  cout << row << endk;
  cout << tmpC << ' ' << tmpR << endk;
  int ib = find(all(col), tmpC) - begin(col);
  int jb = find(all(row), tmpR) - begin(row);
  rep(i, n) {
    rep(j, n) {
      cout << A[row[(ib+i)%n]][col[(jb+j)%n]] << ' ';
    }
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    solve();
    if(T) cout << endk;
  }
  return 0;
}
