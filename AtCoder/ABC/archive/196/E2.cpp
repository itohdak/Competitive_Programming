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
  vector<ll> A(n);
  vector<int> T(n);
  ll diff = 0;
  rep(i, n) {
    cin >> A[i] >> T[i];
    if(T[i] == 1) diff += A[i];
  }
  int q; cin >> q;
  vector<ll> X(q);
  rep(i, q) cin >> X[i];
  vector<int> id(q);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return X[i] < X[j];
  });
  auto bsearchl = [&]() {
    auto test = [&](int mid) {
      ll tmp = X[id[mid]];
      rep(i, n) {
        if(T[i] == 1) {
          tmp += A[i];
        } else if(T[i] == 2) {
          if(tmp < A[i]) return false;
        } else {
          chmin(tmp, A[i]);
        }
      }
      return true;
    };
    int ok = q, ng = -1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  auto bsearchr = [&]() {
    auto test = [&](int mid) {
      ll tmp = X[id[mid]];
      rep(i, n) {
        if(T[i] == 1) {
          tmp += A[i];
        } else if(T[i] == 2) {
          chmax(tmp, A[i]);
        } else {
          if(tmp > A[i]) return false;
        }
      }
      return true;
    };
    int ok = -1, ng = q;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  int l = bsearchl();
  int r = bsearchr();
  ll leftmost = -longinf;
  ll rightmost = longinf;
  rep(i, n) {
    if(T[i] == 1) {
      if(leftmost != -longinf) leftmost += A[i];
      if(rightmost != longinf) rightmost += A[i];
    } else if(T[i] == 2) {
      chmax(leftmost, A[i]);
      chmax(rightmost, A[i]);
    } else {
      chmin(leftmost, A[i]);
      chmin(rightmost, A[i]);
    }
  }
  vector<ll> ans(q);
  rep(i, q) {
    if(i < l) ans[id[i]] = leftmost;
    else if(i > r) ans[id[i]] = rightmost;
    else ans[id[i]] = X[id[i]] + diff;
  }
  // cout << leftmost << ' ' << rightmost << endk;
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
