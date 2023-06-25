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
const ld ldinf = pow(2, 100);
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-15;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> X(n), Y(n); rep(i, n) cin >> X[i] >> Y[i];
  vector<int> cnt(3);
  ll mn = *min_element(all(Y));
  ll mx = *max_element(all(Y));
  if(mn * mx < 0) {
    cout << -1 << endk;
    return 0;
  }
  if(mx < 0) {
    rep(i, n) {
      Y[i] *= -1;
    }
  }
  auto bsearch = [&]() -> ld {
    auto test = [&](ld r) -> bool {
      ld mn = -ldinf;
      ld mx = ldinf;
      rep(i, n) {
        ld val = 2*Y[i]*r - Y[i]*Y[i] + eps;
        if(val < 0) return false;
        chmax(mn, X[i]-(sqrt(val)+eps));
        chmin(mx, X[i]+(sqrt(val)+eps));
      }
      return mx >= mn;
    };
    ld ok = ldinf, ng = 0;
    rep(i, 500) {
      ld mid = (ok+ng)/2 + eps;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << fixed << setprecision(10) << bsearch() << endk;
  return 0;
}
