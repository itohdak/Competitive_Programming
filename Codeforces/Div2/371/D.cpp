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
  int l1, l2, r1, r2;
  int d1, d2, u1, u2;
  auto query = [&](int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int res; cin >> res;
    return res;
  };
  auto ans = [&](int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22) {
    cout << "! "
         << x11 << ' ' << y11 << ' ' << x12 << ' ' << y12
         << ' '
         << x21 << ' ' << y21 << ' ' << x22 << ' ' << y22
         << endl;
  };
  {
    int ok = 0, ng = n;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(1, 1, mid, n);
      (res == 0 ? ok : ng) = mid;
    }
    l1 = ok+1;
  }
  {
    int ok = 0, ng = n;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(1, 1, mid, n);
      (res <= 1 ? ok : ng) = mid;
    }
    l2 = ok+1;
  }
  {
    int ok = n+1, ng = 0;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(mid, 1, n, n);
      (res == 0 ? ok : ng) = mid;
    }
    r2 = ok-1;
  }
  {
    int ok = n+1, ng = 0;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(mid, 1, n, n);
      (res <= 1 ? ok : ng) = mid;
    }
    r1 = ok-1;
  }
  //
  {
    int ok = 0, ng = n;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(1, 1, n, mid);
      (res == 0 ? ok : ng) = mid;
    }
    d1 = ok+1;
  }
  {
    int ok = 0, ng = n;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(1, 1, n, mid);
      (res <= 1 ? ok : ng) = mid;
    }
    d2 = ok+1;
  }
  {
    int ok = n+1, ng = 0;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(1, mid, n, n);
      (res == 0 ? ok : ng) = mid;
    }
    u2 = ok-1;
  }
  {
    int ok = n+1, ng = 0;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      int res = query(1, mid, n, n);
      (res <= 1 ? ok : ng) = mid;
    }
    u1 = ok-1;
  }
  // cout << endl
  //      << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << ' '
  //      << d1 << ' ' << d2 << ' ' << u1 << ' ' << u2 << endl << endl;
  if(l2 <= r1 && d2 <= u1) {
    assert(false);
  } else if(l2 <= r1) {
    int res1 = query(l1, d1, l2, u1);
    int res2 = query(r1, d1, r2, u1);
    if(res1 && res2) ans(l1, d1, r2, u1, l2, d2, r1, u2);
    else if(res1)    ans(l1, d1, r1, u1, l2, d2, r2, u2);
    else if(res2)    ans(l2, d1, r2, u1, l1, d2, r1, u2);
    else             ans(l2, d1, r1, u1, l1, d2, r2, u2);
  } else if(d2 <= u1) {
    int res1 = query(l1, d1, r1, d2);
    int res2 = query(l1, u1, r1, u2);
    if(res1 && res2) ans(l1, d1, r1, u2, l2, d2, r2, u1);
    else if(res1)    ans(l1, d1, r1, u1, l2, d2, r2, u2);
    else if(res2)    ans(l2, d1, r2, u1, l1, d2, r1, u2);
    else             ans(l1, d2, r1, u1, l2, d1, r2, u2);
  } else {
    int res = query(l1, d1, r1, u1);
    if(res) ans(l1, d1, r1, u1, l2, d2, r2, u2);
    else    ans(l2, d1, r2, u1, l1, d2, r1, u2);
  }
  return 0;
}
