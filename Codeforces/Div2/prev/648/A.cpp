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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> A[i][j];
  int cnt1 = 0;
  rep(i, n) {
    bool ok = true;
    rep(j, m) if(A[i][j]) ok = false;
    if(ok) cnt1++;
  }
  int cnt2 = 0;
  rep(j, m) {
    bool ok = true;
    rep(i, n) if(A[i][j]) ok = false;
    if(ok) cnt2++;
  }
  cout << (min(cnt1, cnt2)%2 ? "Ashish" : "Vivek") << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
