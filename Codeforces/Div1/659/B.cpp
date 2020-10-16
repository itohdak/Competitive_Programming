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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> cnt(40);
  rep(i, n) rep(j, 40) cnt[j] += (A[i]>>j)&1;
  rrep(i, 40) {
    if(cnt[i]%2==0) continue;
    int tmp = cnt[i]/2;
    if(n%2) cout << (tmp%2 ? "LOSE" : "WIN") << "\n";
    else    cout << "WIN" << "\n";
    return;
  }
  cout << "DRAW" << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
