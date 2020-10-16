#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(n));
  int rem = k;
  int off = 0;
  while(rem) {
    rep(i, n) {
      if(rem==0) break;
      A[i][(i+off)%n] = 1;
      rem--;
    }
    off++;
  }
  cout << (k%n==0 ? 0 : 2) << "\n";
  rep(i, n) {
    rep(j, n) cout << A[i][j];
    cout << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
