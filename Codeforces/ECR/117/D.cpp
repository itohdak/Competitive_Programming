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
  ll a, b, x; cin >> a >> b >> x;
  if(a > b) swap(a, b);
  while(b >= x) {
    a = min(a, b-a);
    if(a == 0) {
      if(b == x) {
        cout << "YES" << endk;
        return;
      }
      break;
    }
    if(b%a <= x && x <= b && (x-b%a)%a == 0) {
      cout << "YES" << endk;
      return;
    }
    ll nxa = b%a, nxb = a;
    a = nxa, b = nxb;
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
