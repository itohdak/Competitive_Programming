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
  ll n, x, y; cin >> n >> x >> y;
  x--; y--;
  auto calc1 = [&](ll x, ll y) {
    if((x+y+1)%2) {
      ll mid = (x+y+1)/2;
      ll mx = min(mid+1, n-mid-1);
      return mx*2-1+n-mid-1-mx;
    } else {
      ll mid = (x+y+1)/2;
      ll mx = min(mid, n-mid-1);
      return mx*2+n-mid-1-mx;
    }
  };
  auto calc2 = [&](ll x, ll y) {
    if((x+y)%2) {
      ll mid = (x+y)/2;
      ll mx = min(mid+1, n-mid-1);
      return mx*2+mid+1-mx;
    } else {
      ll mid = (x+y)/2;
      ll mx = min(mid, n-mid-1);
      return mx*2+1+mid-mx;
    }
  };
  cout << n-max(calc1(x, y), 0LL) << ' ' << calc2(x, y) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
