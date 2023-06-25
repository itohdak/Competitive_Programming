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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  y = min(2*x, y);
  vector<string> A(n);
  rep(i, n) cin >> A[i];
  ll ans = 0;
  rep(i, n) {
    int j = 0;
    while(j < m) {
      while(j < m && A[i][j] == '*') j++;
      if(j == m) break;
      if(A[i][j] == '.') {
        if(j+1 < m && A[i][j+1] == '.') {
          ans += y;
          A[i][j] = A[i][j+1] = '*';
        } else {
          ans += x;
          A[i][j] = '*';
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
