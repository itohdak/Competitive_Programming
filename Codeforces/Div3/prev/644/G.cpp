#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  // 3 6 4 2
  // 1 1 1 1 x x
  // x x 1 1 1 1
  // 1 1 x x 1 1
  if(n*a != m*b) {
    cout << "NO" << endl;
    return;
  } else {
    cout << "YES" << endl;
    vector<vector<int>> ans(n, vector<int>(m));
    int sj = 0;
    rep(i, n) {
      rep(j, a) {
        ans[i][(sj+j)%m] = 1;
      }
      sj += a*n/b-a;
    }
    rep(i, n) {
      rep(j, m) cout << ans[i][j];
      cout << endl;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
