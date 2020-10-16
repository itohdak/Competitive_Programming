#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

void solve() {
  int n, m; cin >> n >> m;
  vector<string> in(n);
  vector<vector<int>> S(n, vector<int>(m));
  rep(i, n) {
    cin >> in[i];
    rep(j, m) S[i][j] = in[i][j]-'0';
  }
  if(n >= 4 && m >= 4) {
    cout << -1 << endk;
    return;
  }
  if(n == 1 || m == 1) {
    cout << 0 << endk;
    return;
  }
  if(n >= 4) { // transpose
    vector<vector<int>> tmp(m, vector<int>(n));
    rep(i, n) rep(j, m) tmp[j][i] = S[i][j];
    swap(n, m);
    S = vector<vector<int>>(n, vector<int>(m));
    rep(i, n) rep(j, m) S[i][j] = tmp[i][j];
    assert(n < 4);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
