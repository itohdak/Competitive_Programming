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
  int n; cin >> n;
  string s; cin >> s;
  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + (s[i]-'0');
  rep(i, n+1) sum[i] -= i;
  map<ll, ll> cnt;
  rep(i, n+1) cnt[sum[i]]++;
  ll ans = 0;
  for(auto ele: cnt) {
    ll m = ele.second;
    ans += m * (m-1) / 2;
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
