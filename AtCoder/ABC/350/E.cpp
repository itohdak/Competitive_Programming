#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; int a; ll x, y; cin >> n >> a >> x >> y;
  map<ll, ld> mp;
  priority_queue<ll> q;
  q.push(n);
  mp[n] = 0;
  while(q.size()) {
    ll cur = q.top(); q.pop();
    for(int i=2; i<=6; i++) {
      ll nx = cur/i;
      if(mp.count(nx)) continue;
      mp[nx] = 0;
      q.push(nx);
    }
  }
  // cout << mp.size() << endk;
  for(auto& [k, v]: mp) {
    if(k == 0) {
      v = 0;
      continue;
    }
    ld tmp = 0;
    for(int i=2; i<=6; i++) tmp += mp[k/i];
    v = min((tmp+6*y)/5, mp[k/a]+x);
  }
  cout << fixed << setprecision(10) << mp[n] << endk;
  return 0;
}
