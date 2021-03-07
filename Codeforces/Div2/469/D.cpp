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
  ll n; int q; cin >> n >> q;
  ll pw = 1;
  while(pw < n) pw <<= 1;
  rep(_, q) {
    ll x; cin >> x;
    x--;
    ll begin = 0;
    ll end = n;
    while(1) {
      if(!(x&1)) {
        cout << x/2+1 << endl;
        break;
      }
      x = end + (x - begin) / 2;
      ll nextEnd = end + (end - begin + (begin&1)) / 2;
      ll nextBegin = end;
      end  = nextEnd;
      begin = nextBegin;
    }
  }
  return 0;
}
