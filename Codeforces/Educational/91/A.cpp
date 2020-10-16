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
  vector<int> pos(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
    pos[A[i]] = i;
  }
  int l = 0, r = n-1;
  rrep(i, n) {
    if(l < pos[i] && pos[i] < r) {
      cout << "YES" << "\n";
      cout << l+1 << ' ' << pos[i]+1 << ' ' << r+1 << "\n";
      return;
    } else if(l == pos[i]) {
      l++;
    } else {
      r--;
    }
  }
  cout << "NO" << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
