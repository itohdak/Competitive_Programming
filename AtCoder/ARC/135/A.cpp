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

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod2;
    (tmp *= tmp) %= mod2;
    N /= 2;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll x; cin >> x;
  map<ll, ll> cnt;
  cnt[x] = 1;
  while(1) {
    map<ll, ll> next;
    ll mx = 0;
    for(auto [k, v]: cnt) {
      if(k <= 3) next[k] += v;
      else {
        next[k/2] += v;
        next[(k+1)/2] += v;
        chmax(mx, (k+1)/2);
      }
    }
    if(mx <= 3) {
      ll ans = 1;
      // cout << next << endk;
      for(auto [k, v]: next) (ans *= modpow(k, v)) %= mod2;
      cout << ans << endk;
      break;
    } else {
      cnt = next;
    }
  }
  return 0;
}
