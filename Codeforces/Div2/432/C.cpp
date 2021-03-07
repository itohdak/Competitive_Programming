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

bool isNotAcute(tuple<ll, ll, ll, ll, ll> p1,
                tuple<ll, ll, ll, ll, ll> p2,
                tuple<ll, ll, ll, ll, ll> p3) {
    auto [a1, b1, c1, d1, e1] = p1;
    auto [a2, b2, c2, d2, e2] = p2;
    auto [a3, b3, c3, d3, e3] = p3;
    a2 -= a1; a3 -= a1;
    b2 -= b1; b3 -= b1;
    c2 -= c1; c3 -= c1;
    d2 -= d1; d3 -= d1;
    e2 -= e1; e3 -= e1;
    // cout << a2*a3+b2*b3+c2*c3+d2*d3+e2*e3 << endk;
    return a2*a3+b2*b3+c2*c3+d2*d3+e2*e3 <= 0;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<tuple<ll, ll, ll, ll, ll>> P(n);
  rep(i, n) {
    ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    P[i] = {a, b, c, d, e};
  }
  queue<int> q;
  rep(i, n) q.push(i);
  while(q.size() >= 3) {
    int i = q.front(); q.pop();
    int j = q.front(); q.pop();
    int k = q.front(); q.pop();
    assert(i != j && j != k && k != i);
    if(isNotAcute(P[i], P[j], P[k])) q.push(i);
    if(isNotAcute(P[j], P[k], P[i])) q.push(j);
    if(isNotAcute(P[k], P[i], P[j])) q.push(k);
  }
  vector<int> ans;
  while(q.size()) {
    int i = q.front(); q.pop();
    bool ok = true;
    rep(j, n) rep(k, n) {
      if(i == j || j == k || k == i) continue;
      if(!isNotAcute(P[i], P[j], P[k])) ok = false;
    }
    if(ok) ans.push_back(i+1);
  }
  if(ans.size()) {
    cout << ans.size() << endk;
    for(int a: ans) cout << a << ' ';
    cout << endk;
  } else {
    cout << 0 << endk;
  }
  return 0;
}
