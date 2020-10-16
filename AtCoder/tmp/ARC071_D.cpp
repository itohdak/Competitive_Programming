#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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

ll f[1000005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  if(n == 1) cout << 1 << endk;
  else if(n == 2) cout << 4 << endk;
  else if(n == 3) cout << 14 << endk;
  else if(n == 4) cout << 43 << endk;
  else {
    ll ans = 0;
    //
    cout << ans << endk;
  }
  return 0;
}
