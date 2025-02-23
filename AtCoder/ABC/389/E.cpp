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
  int n; ll m; cin >> n >> m;
  vector<ll> P(n); rep(i, n) cin >> P[i];
  auto bsearch = [&]() {
    auto test = [&](ll t) {
      ll sum = 0;
      rep(i, n) {
        // (2*k-1)*pi <= t
        ll k = (t/P[i]+1)/2;
        if(k == 0) continue;
        if(m/P[i]/k < k) return false;
        ll sumtmp = k*k*P[i];
        if(sum > m - sumtmp) return false;
        sum += sumtmp;
      }
      return sum <= m;
    };
    ll ok = 0, ng = m;
    while(ng-ok > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll t = bsearch();
  ll cnt = 0;
  ll sum = 0;
  rep(i, n) {
    // (2*k-1)*pi <= t
    ll k = (t/P[i]+1)/2;
    ll sumtmp = k*k*P[i];
    sum += sumtmp;
    cnt += k;
  }
  while(sum+(t+1) <= m) {
    sum += t+1;
    cnt++;
  }
  cout << cnt << endk;
  return 0;
}
