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
  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  ll xs, ys, t;
  cin >> xs >> ys >> t;
  vector<ll> pwx, pwy;
  vector<ll> Spwx, Spwy;
  {
    ll pw = 1;
    pwx.push_back(pw);
    while(longinf/ax >= pw) {
      pw *= ax;
      pwx.push_back(pw);
    }
    ll sum = 0;
    Spwx.push_back(sum);
    rep(i, pwx.size()) {
      sum += pwx[i];
      Spwx.push_back(sum);
    }
  }
  {
    ll pw = 1;
    pwy.push_back(pw);
    while(longinf/ay >= pw) {
      pw *= ay;
      pwy.push_back(pw);
    }
    ll sum = 0;
    Spwy.push_back(sum);
    rep(i, pwy.size()) {
      sum += pwy[i];
      Spwy.push_back(sum);
    }
  }
  // cout << pwx << endl;
  // cout << pwy << endl;
  // cout << Spwx << endl;
  // cout << Spwy << endl;

  vector<pair<ll, ll>> P;
  int n = min(pwx.size(), pwy.size());
  rep(i, n) {
    if(longinf/x0 < pwx[i] || (bx != 0 && longinf/bx < Spwx[i])) break;
    if(longinf/y0 < pwy[i] || (by != 0 && longinf/by < Spwy[i])) break;
    ll xi = x0 * pwx[i] + (bx == 0 ? 0 : bx * Spwx[i]);
    ll yi = y0 * pwy[i] + (by == 0 ? 0 : by * Spwy[i]);
    P.push_back({xi, yi});
  }
  // cout << P << endk;
  auto dist = [&](pair<ll, ll> p1, pair<ll, ll> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
  };
  // cout << P << endk;
  n = P.size();
  int ans = 0;
  rep(i, n) { // first
    ll d = dist({xs, ys}, P[i]);
    // cout << i << ' ' << d << endk;
    if(d > t) continue;
    ll rem = t - d;
    for(int j=0; j<=i; j++) {
      ll d2 = dist(P[i], P[j]);
      if(d2 > rem) continue;
      ll rem2 = rem - d2;
      int k = j;
      while(k < n && dist(P[j], P[k]) <= rem2) k++;
      // cout << i << ' ' << j << ' ' << k << endk;
      chmax(ans, i-j+1+max(0, k-1-i));
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
