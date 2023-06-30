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

vector<string> cut(int h, int w, vector<string> A) {
  int h1 = h, h2 = 0;
  rep(i, h) {
    bool ok = false;
    rep(j, w) if(A[i][j] == '#') ok = true;
    if(ok) {
      chmin(h1, i);
      chmax(h2, i+1);
    }
  }
  int w1 = w, w2 = 0;
  rep(j, w) {
    bool ok = false;
    rep(i, h) if(A[i][j] == '#') ok = true;
    if(ok) {
      chmin(w1, j);
      chmax(w2, j+1);
    }
  }
  vector<string> tmp(h2-h1, string(w2-w1, '.'));
  REP(i, h1, h2) REP(j, w1, w2) {
    tmp[i-h1][j-w1] = A[i][j];
  }
  return tmp;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ha, wa; cin >> ha >> wa;
  vector<string> A(ha);
  rep(i, ha) cin >> A[i];
  int hb, wb; cin >> hb >> wb;
  vector<string> B(hb);
  rep(i, hb) cin >> B[i];
  int hx, wx; cin >> hx >> wx;
  vector<string> X(hx);
  rep(i, hx) cin >> X[i];

  auto tmpA = cut(ha, wa, A);
  A = tmpA;
  ha = tmpA.size(), wa = tmpA[0].size();
  auto tmpB = cut(hb, wb, B);
  B = tmpB;
  hb = tmpB.size(), wb = tmpB[0].size();

  if(ha > hx || wa > wx || hb > hx || wb > wx) {
    cout << "No" << endk;
    return 0;
  }
  rep(i, hx-ha+1) rep(j, wx-wa+1) rep(k, hx-hb+1) rep(l, wx-wb+1) {
    bool ok = true;
    rep(i2, hx) rep(j2, wx) {
      bool black = false;
      {
        int p = i2-i, q = j2-j;
        if(p >= 0 && p < ha && q >= 0 && q < wa) {
          if(A[p][q] == '#') black = true;
        }
      }
      {
        int p = i2-k, q = j2-l;
        if(p >= 0 && p < hb && q >= 0 && q < wb) {
          if(B[p][q] == '#') black = true;
        }
      }
      if(black != (X[i2][j2] == '#')) {
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
