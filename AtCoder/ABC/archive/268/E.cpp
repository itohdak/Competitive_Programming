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
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<int> invP(n); rep(i, n) invP[P[i]] = i;
  vector<int> cnt(n+1);
  auto apply = [&](int l, int r, int d) {
    if(l <= r) {
      cnt[l] += d; cnt[r] -= d;
    } else {
      cnt[l] += d; cnt[n] -= d;
      cnt[0] += d; cnt[r] -= d;
    }
  };
  rep(i, n) {
    int l, r;
    l = ((i-n/2)-invP[i]+2*n)%n, r = (i-invP[i]+n)%n;
    apply(l, r, -1);
    l = (i-invP[i]+n)%n, r = ((i+n/2)-invP[i]+n)%n;
    apply(l, r, +1);
    // if(n%2) {
    //   // [i-n/2, i): decrease
    //   // [i, i+n/2): increase
    //   // i+n/2+1   : unchange
    //   int l, r;
    //   l = ((i-n/2)-invP[i]+2*n)%n, r = (i-invP[i]+n)%n;
    //   apply(l, r, -1);
    //   l = (i-invP[i]+n)%n, r = ((i+n/2)-invP[i]+n)%n;
    //   apply(l, r, +1);
    // } else {
    //   // [i-n/2, i): decrease
    //   // [i, i+n/2): increase
    //   int l, r;
    //   l = ((i-n/2)-invP[i]+2*n)%n, r = (i-invP[i]+n)%n;
    //   apply(l, r, -1);
    //   l = (i-invP[i]+n)%n, r = ((i+n/2)-invP[i]+n)%n;
    //   apply(l, r, +1);
    // }
  }
  rep(i, n) cnt[i+1] += cnt[i];
  ll tmp = 0;
  rep(i, n) {
    int d = abs(invP[i] - i);
    tmp += min(d, n-d);
  }
  ll ans = tmp;
  rep(i, n) {
    chmin(ans, tmp);
    tmp += cnt[i];
  }
  cout << ans << endk;
  return 0;
}
