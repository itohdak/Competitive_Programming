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
  int n; ll x; cin >> n >> x;
  priority_queue<ll> q;
  rep(i, n) {
    ll a; cin >> a;
    q.push(a);
  }
  int ans = 0;
  int m = 0;
  while(!q.empty()) {
    ll cur = q.top(); q.pop();
    m++;
    if(cur * m >= x) {
      ans++;
      m = 0;
    }
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
