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
  vector<int> v(4);
  rep(i, 4) cin >> v[i];
  if(v[3] > v[2]*2 || v[3]*2 < v[2] || v[3] >= v[1]) {
    cout << -1 << endk;
    return 0;
  }
  vector<int> ans(3);
  ans[0] = v[0]*2;
  ans[1] = v[1]*2;
  ans[2] = max(v[2], v[3]);
  rep(i, 3) cout << ans[i] << endk;
  return 0;
}
