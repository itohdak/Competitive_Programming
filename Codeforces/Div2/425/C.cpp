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
  int n, s; cin >> n >> s;
  vector<tuple<int, int, int>> D(n);
  rep(i, n) {
    int x, v, t; cin >> x >> v >> t;
    D[i] = {x, t, v};
  }
  sort(all(D));
  bool ok = true;
  int flag = 1;
  int changepoint = n;
  rep(i, n) {
    auto [x, t, v] = D[i];
    if(t == flag) {
    } else if(t > flag) {
      flag = t;
      changepoint = i;
    } else {
      ok = false;
    }
  }
  if(ok) {
    if(changepoint == 0) {
    } else if(changepoint == n) {
    } else {
      auto [x0, t0, v0] = D[changepoint-1];
      auto [x1, t1, v1] = D[changepoint];
      auto time = [&](ld x, ld v, int t, ld b) {
        if(t == 1) {
          assert(x <= b);
          ld t1 = (b-x)/(s-v);
          ld t2 = (x-v*t1)/s;
          return min(x/v, t1+t2);
        } else {
          assert(x >= b);
          ld t1 = (x-b)/(s-v);
          ld t2 = ((ld)1000000-x-v*t1)/s;
          return min(((ld)1000000-x)/v, t1+t2);
        }
      };
      ld ok = x0, ng = x1;
      rep(i, 50) {
        ld mid = (ok+ng)/2;
        (time(x0, v0, t0, mid) <= time(x1, v1, t1, mid) ? ok : ng) = mid;
      }
      cout << ok << endk;
    }
  } else {
  }
  return 0;
}
