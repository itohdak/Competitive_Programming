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
  int n; cin >> n;
  vector<tuple<ll, ll, ll>> A(n);
  for(auto& [x, y, c]: A) {
    cin >> x >> y >> c;
    x *= 2;
    y *= 2;
  }
  map<tuple<ll, ll, ll, ll>, vector<pair<ll, ll>>> mp;
  rep(i, n) REP(j, i+1, n) {
    auto [x1, y1, c1] = A[i];
    auto [x2, y2, c2] = A[j];
    ll xm = (x1+x2)/2, ym = (y1+y2)/2;
    ll dx = y1-y2, dy = -(x1-x2);
    ll rx, ry;
    ll m;
    if(dx == 0) {
      dy = 1;
      rx = xm, ry = 0;
      m = ym;
    } else {
      if(dx < 0) dx = -dx, dy = -dy;
      ll g = __gcd(dx, abs(dy));
      dx /= g;
      dy /= g;
      m = xm/dx;
      rx = xm-m*dx;
      ry = ym-m*dy;
      if(rx < 0) {
        rx += dx;
        ry += dy;
        m--;
      }
    }
    mp[{dx, dy, rx, ry}].push_back({c1+c2, m});
  }
  ll ans = -1;
  for(auto [k, v]: mp) {
    map<ll, vector<ll>> mp2;
    for(auto [c, m]: v) {
      mp2[m].push_back(c);
    }
    vector<ll> u;
    for(auto& [_, v]: mp2) {
      sort(all(v), greater<ll>());
      u.push_back(v[0]);
    }
    sort(all(u), greater<ll>());
    if(u.size() < 2) continue;
    chmax(ans, u[0]+u[1]);
  }
  cout << ans << endk;
  return 0;
}
