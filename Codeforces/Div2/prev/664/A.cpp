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
  ll r, g, b, w; cin >> r >> g >> b >> w;
  ll sum = r+g+b+w;
  int parity = r%2+g%2+b%2+w%2;
  bool nonzero = r!=0 && g!=0 && b!=0;
  if(sum % 2 == 0) {
    if(parity == 0) cout << "Yes" << endk;
    else if(parity == 4 && nonzero) cout << "Yes" << endk;
    else cout << "No" << endk;
  } else {
    if(parity == 1) cout << "Yes" << endk;
    else if(parity == 3 && nonzero) cout << "Yes" << endk;
    else cout << "No" << endk;
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
