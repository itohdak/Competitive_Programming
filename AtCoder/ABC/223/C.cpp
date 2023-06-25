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
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  vector<ld> cum(n+1);
  rep(i, n) cum[i+1] = cum[i] + A[i];
  vector<ld> cum2(n+1);
  rep(i, n) cum2[i+1] = cum2[i] + (ld)1*A[i]/B[i];
  // cout << cum << endk;
  // cout << cum2 << endk;
  auto bsearch = [&]() {
    auto test = [&](ld m) {
      int i = lower_bound(all(cum), m) - begin(cum);
      ld t1 = cum2[i-1] + (ld)1*(m-cum[i-1])/B[i-1];
      ld t2 = cum2[n]-t1;
      // cout << m << ' ' << t1 << ' ' << t2 << endk;
      return t1 >= t2;
    };
    ld ok = cum[n], ng = 0;
    while(ok-ng > eps) {
      ld mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << fixed << setprecision(10) << bsearch() << endk;
  return 0;
}
