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
  ll n;
  cin >> n;
  int cnt2=0, cnt3=0;
  while(n%2==0) {
    cnt2++;
    n /= 2;
  }
  while(n%3==0) {
    cnt3++;
    n /= 3;
  }
  if(n != 1) cout << -1 << "\n";
  else if(cnt2 > cnt3) cout << -1 << "\n";
  else cout << 2*cnt3-cnt2 << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
