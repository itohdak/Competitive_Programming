#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  int n, q; cin >> n >> q;
  map<int, int> R, C;
  int mnR = n-1, mnC = n-1;
  ll ans = 0;
  rep(i, q) {
    int t, x; cin >> t >> x;
    x--;
    if(t == 1) {
      auto itr = C.upper_bound(x);
      if(itr == C.begin()) ans += mnR-1;
      else ans += (--itr)->second-1;
      if(x < mnC) {
        chmin(mnC, x);
        C[x] = mnR;
      }
    } else {
      auto itr = R.upper_bound(x);
      if(itr == R.begin()) ans += mnC-1;
      else ans += (--itr)->second-1;
      if(x < mnR) {
        chmin(mnR, x);
        R[x] = mnC;
      }
    }
  }
  cout << 1LL*(n-2)*(n-2)-ans << endk;
  return 0;
}
