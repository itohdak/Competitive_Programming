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
  // 40
  // 6 10 14 15 21, 1 2 3 4 5 7 8 9 11 12 13
  if(n >= 45) {
    cout << "YES\n";
    cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n-30 << "\n";
  } else if(n <= 30) {
    cout << "NO\n";
  } else if(n == 36) {
    cout << "YES\n";
    cout << 5 << ' ' << 6 << ' ' << 10 << ' ' << 15 << "\n";
  } else if(n == 40) {
    cout << "YES\n";
    cout << 5 << ' ' << 6 << ' ' << 14 << ' ' << 15 << "\n";
  } else if(n == 44) {
    cout << "YES\n";
    cout << 6 << ' ' << 7 << ' ' << 10 << ' ' << 21 << "\n";
  } else {
    cout << "YES\n";
    cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n-30 << "\n";
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
