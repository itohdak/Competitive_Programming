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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> A(n);
  int sum = 0;
  int mn = inf, mx = -inf;
  rep(i, n) {
    if(s[i] != t[i]) {
      A[i] = (s[i]=='1' ? 1 : -1);
    }
    sum += A[i];
    mn = min(sum, mn);
    mx = max(sum, mx);
  }
  if(sum != 0) {
    cout << -1 << endl;
    return;
  }
  cout << mx - mn << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
