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
  int l, r; cin >> l >> r;
  ll ans = 0;
  vector<ll> cnt(1000001);
  for(int i=r; i>=2; i--) {
    int lb = (l+i-1)/i;
    int rb = r/i;
    // [lb, rb]
    ll c = rb-lb+1;
    cnt[i] = c*(c-1);
    for(int j=i*2; j<=r; j+=i) {
      cnt[i] -= cnt[j];
    }
    if(lb > 1) ans += cnt[i];
    else ans += cnt[i] - (c-1)*2;
  }
  cout << ans << endk;
  return 0;
}
