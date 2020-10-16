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
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> ok(n+1);
  rep(i, n) if(s[i] == '1') {
    ok[max(0, i-k)]++;
    ok[min(n, i+k+1)]--;
  }
  rep(i, n) ok[i+1] += ok[i];
  int l = 0, r = 0;
  int ans = 0;
  // cout << ok << endl;
  while(l < n) {
    while(l < n && ok[l] > 1) l++;
    r = l;
    while(r < n && ok[r] == 0) r++;
    // cout << l << ' ' << r << endl;
    ans += (r-l+k) / (k+1);
    l = r+1;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
