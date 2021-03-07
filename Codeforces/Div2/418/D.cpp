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
const ld pi = 3.14159265358979;

bool inside(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2) {
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= (r1-r2)*(r1-r2);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<tuple<int, int, int>> C(n);
  rep(i, n) {
    int x, y, r; cin >> x >> y >> r;
    C[i] = {r, x, y};
  }
  sort(all(C), greater<tuple<int, int, int>>());
  vector<int> S1, S2;
  vector<int> sign(n, 1);
  rep(i, n) {
    auto [r2, x2, y2] = C[i];
    int s1 = 1;
    for(int j: S1) {
      auto [r1, x1, y1] = C[j];
      if(inside(x1, y1, r1, x2, y2, r2)) {
        s1 = sign[j] * -1;
      }
    }
    int s2 = 1;
    for(int j: S2) {
      auto [r1, x1, y1] = C[j];
      if(inside(x1, y1, r1, x2, y2, r2)) {
        s2 = sign[j] * -1;
      }
    }
    if(s1 == 1) {
      sign[i] = s1;
      S1.push_back(i);
    } else if(s2 == 1) {
      sign[i] = s2;
      S2.push_back(i);
    } else {
      sign[i] = s1;
      S1.push_back(i);
    }
  }
  ll ans = 0;
  rep(i, n) {
    auto [r, x, y] = C[i];
    ans += 1LL * sign[i] * r * r;
  }
  cout << fixed << setprecision(20) << pi * ans << endk;
  return 0;
}
