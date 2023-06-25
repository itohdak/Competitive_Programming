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
  ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
  vector<ll> A = {a, b, c};
  auto dfs = [&](auto dfs, ll w, ll h, int done) -> bool {
    // cout << w << ' ' << h << ' ' << done << endk;
    if(done == (1<<A.size())-1) {
      return true;
    }
    if(w == 0 || h == 0) return false;
    rep(i, 3) {
      if(!((done>>i)&1)) {
        if((A[i]+w-1)/w <= h) {
          if(dfs(dfs, w, h-(A[i]+w-1)/w, done^1<<i)) return true;
        }
        if((A[i]+h-1)/h <= w) {
          if(dfs(dfs, w-(A[i]+h-1)/h, h, done^1<<i)) return true;
        }
      }
    }
    return false;
  };
  cout << (dfs(dfs, x, y, 0) ? "Yes" : "No") << endk;
  return 0;
}
