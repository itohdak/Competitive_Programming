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
  int n; cin >> n;
  vector<int> A(n);
  int l = -1, r = -1, cnt = 0;
  rep(i, n) {
    cin >> A[i];
    if(A[i] != i+1) {
      if(l == -1) l = i;
      r = i;
      cnt++;
    }
  }
  if(l == -1) cout << 0 << "\n";
  else if(cnt == r-l+1) cout << 1 << "\n";
  else cout << 2 << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
