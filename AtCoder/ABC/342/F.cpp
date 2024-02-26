#include <bits/stdc++.h>
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
  int n, l, d; cin >> n >> l >> d;

  auto calc_exp = [&](int L) -> vector<ld> {
    vector<ld> exp(n+2);
    vector<ld> cum(n+3);
    exp[0] = 1;
    rep(i, n+2) {
      exp[i] += cum[i];
      if(i < L) {
        cum[i+1] += exp[i]/d;
        cum[min(i+d, n+1)+1] -= exp[i]/d;
        exp[i] = 0;
      }
      cum[i+1] += cum[i];
    }
    exp[n+1] = 1-accumulate(all(exp), (ld)0)+exp[n+1];
    return exp;
  };
  vector<ld> E0 = calc_exp(l);

  auto calc_win_rate = [&](vector<ld> E) -> ld {
    vector<ld> cum(n+2);
    rrep(i, n+1) {
      cum[i] = cum[i+1] + E[i];
    }
    ld ans = 0;
    rep(i, n+1) {
      ans += E0[i] * cum[i+1];
    }
    ans += E0[n+1];
    return ans;
  };

  auto bsearch = [&]() -> int {
    auto test = [&](int m) -> bool {
      vector<ld> E1 = calc_exp(m);
      vector<ld> E2 = calc_exp(m+1);
      ld w1 = calc_win_rate(E1);
      ld w2 = calc_win_rate(E2);
      return w1 <= w2;
    };
    int ok = 0, ng = n;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };

  int ret = bsearch();
  vector<ld> E = calc_exp(ret+1);
  ld w = calc_win_rate(E);
  cout << fixed << setprecision(10) << w << endk;

  return 0;
}
