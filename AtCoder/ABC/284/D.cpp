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
  int t; cin >> t;
  rep(i, t) {
    ll n; cin >> n;
    for(int j=2; j<=3000000; j++) {
      {
        ll q = j;
        if(n%q) continue;
        ll p2 = n/q;
        ll p = sqrt(p2);
        if(p*p==p2) {
          cout << p << ' ' << q << endk;
          break;
        }
      }
      {
        ll p = j;
        ll p2 = p*p;
        if(n%p2) continue;
        ll q = n/p2;
        cout << p << ' ' << q << endk;
        break;
      }
    }
  }
  return 0;
}
