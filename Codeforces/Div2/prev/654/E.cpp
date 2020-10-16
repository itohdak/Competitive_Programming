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
  int n, p;
  cin >> n >> p;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  sort(all(A));
  ll mx = *max_element(all(A));
  vector<int> ans;
  for(int i=1; i<=mx; i++) {
    ll cur = 1;
    rep(j, n) {
      (cur *= upper_bound(all(A), i+j)-begin(A)-j) %= p;
    }
    // cout << i << ' ' << cur << "\n";
    if(cur) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for(int a: ans) cout << a << ' ';
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
