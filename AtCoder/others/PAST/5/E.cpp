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
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<string> T(h); rep(i, h) cin >> T[i];
  int xmin=inf, xmax=-1, ymin=inf, ymax=-1;
  rep(i, h) rep(j, w) {
    if(T[i][j] == '#') {
      chmin(xmin, i);
      chmax(xmax, i);
      chmin(ymin, j);
      chmax(ymax, j);
    }
  }
  int th = xmax-xmin+1, tw = ymax-ymin+1;
  vector<string> U(th);
  rep(i, th) U[i] = T[xmin+i].substr(ymin, tw);
  rep(i, h) rep(j, w) {
    if(i+th > h || j+tw > w) continue;
    bool ok1 = true, ok2 = true;
    rep(k, th) rep(l, tw) {
      if(U[k][l] == '#' && S[i+k][j+l] == '#') ok1 = false;
      if(U[th-1-k][tw-1-l] == '#' && S[i+k][j+l] == '#') ok2 = false;
    }
    if(ok1 || ok2) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  rep(i, h) rep(j, w) {
    if(i+tw > h || j+th > w) continue;
    bool ok1 = true, ok2 = true;
    rep(k, th) rep(l, tw) {
      if(U[k][tw-1-l] == '#' && S[i+l][j+k] == '#') ok1 = false;
      if(U[th-1-k][l] == '#' && S[i+l][j+k] == '#') ok2 = false;
    }
    if(ok1 || ok2) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
