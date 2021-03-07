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
  ll b, c; cin >> b >> c;
  ll mx1, mx2, mn1, mn2;
  if(b >= 0) {
    mx1 = (c>1 ? b+(c-2)/2 : b);
    mn1 = b-c/2;
    mx2 = -(b-(c-1)/2);
    mn2 = -b-(c-1)/2;
    cout << max(mx1, mx2) - min(mn1, mn2) + 1 - max(0LL, mn1 - mx2 - 1) << endk;
  } else {
    mx1 = (c>1 ? b+(c-2)/2 : b);
    mn1 = b-c/2;
    mx2 = -(b-(c-1)/2);
    mn2 = -b-(c-1)/2;
    cout << max(mx1, mx2) - min(mn1, mn2) + 1 - max(0LL, mn2 - mx1 - 1) << endk;
  }
  return 0;
}
