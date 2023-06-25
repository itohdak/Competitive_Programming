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

ll white(ll x1, ll y1, ll x2, ll y2) {
  if(x1 >= x2 || y1 >= y2) return 0;
  return (x2*y2+1)/2 - (x1*y2+1)/2 - (x2*y1+1)/2 + (x1*y1+1)/2;
}
ll black(ll x1, ll y1, ll x2, ll y2) {
  if(x1 >= x2 || y1 >= y2) return 0;
  return (x2-x1)*(y2-y1) - white(x1, y1, x2, y2);
}
void solve() {
  ll n, m; cin >> n >> m;
  ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  ll x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
  x1--; y1--; x3--; y3--;
  ll w = white(0, 0, n, m);
  w += black(x1, y1, x2, y2);
  w -= black(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));
  w -= white(x3, y3, x4, y4);
  cout << w << ' ' << n*m-w << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
