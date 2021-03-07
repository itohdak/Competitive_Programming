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
  int n; ll h; cin >> n >> h;
  vector<pair<ll, ll>> X(n);
  rep(i, n) {
    cin >> X[i].first >> X[i].second;
  }
  sort(all(X));
  vector<ll> sum(n+1);
  rep(i, n) {
    sum[i+1] = sum[i] + X[i].second - X[i].first;
  }
  auto bsearch = [&](ll start) {
    auto test = [&](ll mid) {
      ll end = start + mid;
      int i = lower_bound(all(X), make_pair(start, start)) - begin(X);
      int j = upper_bound(all(X), make_pair(end-1, longinf)) - begin(X);
      // cout << start << ' ' << end << ' ' << i << ' ' << j << ' ' << sum[j] - sum[i] << endk;
      ll asc = sum[j-1] - sum[i] + (min(X[j-1].second, end)-X[j-1].first);
      ll rem = h - (mid - asc);
      if(end > X[j-1].second) {
        return rem >= 0;
      } else {
        return rem > 0;
      }
    };
    ll ok = 0, ng = longinf;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll ans = 0;
  rep(i, n) {
    ll ret = bsearch(X[i].first);
    // cout << X[i] << ' ' << ret << endk;
    chmax(ans, ret);
  }
  cout << ans << endk;
  return 0;
}
