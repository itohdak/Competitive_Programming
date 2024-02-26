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

ll modpow(ll a, ll N, ll mod=mod) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int q; cin >> q;
  rep(_, q) {
    int x; cin >> x;
    int cur = 0;
    for(int i=1; i<100; i++) {
      if(modpow(i, i, 100) == x%100) {
        cur = i;
        break;
      }
    }
    int pw = 100;
    for(int i=2; i<9; i++) {
      rep(j, 10) {
        int ne = cur + pw * j;
        if(modpow(ne, ne, pw*10) == x%(pw*10)) {
          cur = ne;
          break;
        }
      }
      pw *= 10;
    }
    cout << cur << endk;
  }
  return 0;
}
