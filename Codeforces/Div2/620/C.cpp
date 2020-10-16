#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; ll m; cin >> n >> m;
  map<ll, pair<ll, ll>> mp;
  rep(i, n) {
    ll t, l, h; cin >> t >> l >> h;
    if(!mp.count(t)) mp[t] = {-longinf, longinf};
    chmax(mp[t].first, l);
    chmin(mp[t].second, h);
  }
  pair<ll, ll> prev = {m, m};
  ll prevt = 0;
  for(auto ele: mp) {
    ll dt = ele.first - prevt;
    ll l = prev.first - dt;
    ll h = prev.second + dt;
    prev.first = max(l, ele.second.first);
    prev.second = min(h, ele.second.second);
    prevt = ele.first;
    if(prev.first > prev.second) {
      cout << "NO" << endk;
      return;
    }
  }
  cout << "YES" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
