#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  vector<int> X(n), Y(n);
  map<int, vector<int>> mp;
  rep(i, n) cin >> X[i] >> Y[i];
  auto bsearch = [&]() {
    auto test = [&](ld r) {
      dsu uf(n+2);
      rep(i, n) {
        if(100-Y[i] < 2*r+eps) uf.merge(n, i);
        if(Y[i]+100 < 2*r+eps) uf.merge(n+1, i);
      }
      rep(i, n) REP(j, i+1, n) {
        if((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]) < 4*r*r+eps) {
          uf.merge(i, j);
        }
      }
      return !uf.same(n, n+1);
    };
    ld ok = 0, ng = 101;
    rep(i, 100) {
      ld mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << fixed << setprecision(10) << bsearch() << endk;
  return 0;
}
