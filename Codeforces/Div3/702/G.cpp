#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> sum(n+1); rep(i, n) sum[i+1] = sum[i] + A[i];
  vector<ll> sumMax(n+1);
  rep(i, n+1) sumMax[i] = sum[i];
  rep(i, n) chmax(sumMax[i+1], sumMax[i]);
  ll mx = sumMax[n];
  auto bsearch = [&](ll x) {
    auto test = [&](ll mid) {
      if(mid-1 > 0 && x / (mid-1) < sum[n]) return false;
      return sum[n] * (mid-1) + mx < x;
    };
    ll ok = 0, ng = longinf;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  rep(i, m) {
    ll x; cin >> x;
    if(sum[n] <= 0) {
      int j = lower_bound(all(sumMax), x)-begin(sumMax)-1;
      if(j == n) {
        cout << -1 << ' ';
      } else {
        cout << j << ' ';
      }
    } else {
      auto ret = bsearch(x);
      ll tmp = sum[n] * ret;
      assert(x-tmp > 0);
      cout << ret * n + (lower_bound(all(sumMax), x-tmp)-begin(sumMax)-1) << ' ';
    }
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
