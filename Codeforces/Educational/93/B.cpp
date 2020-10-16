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
  string s; cin >> s;
  vector<int> cnt;
  int l = 0, r = 0;
  int n = s.size();
  while(l < n) {
    while(l < n && s[l]=='0') l++;
    r = l;
    while(r < n && s[r]=='1') r++;
    cnt.push_back(r-l);
    l = r;
  }
  sort(all(cnt), greater<ll>());
  int ans = 0;
  rep(i, cnt.size()) {
    if(i%2==0) ans += cnt[i];
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
