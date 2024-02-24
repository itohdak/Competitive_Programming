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
  int n; cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll ans = longinf;
  auto dfs = [&](auto dfs, int d, vector<int> v, ll b) -> void {
    if(d == -1) {
      ll mx = 0;
      for(int i: v) {
        chmax(mx, A[i]^b);
      }
      chmin(ans, mx);
      return;
    }
    vector<int> v1, v2;
    for(int i: v) {
      if((A[i]>>d)&1) {
        v1.push_back(i);
      } else {
        v2.push_back(i);
      }
    }
    if(v1.empty()) {
      dfs(dfs, d-1, v2, b);
    } else if(v2.empty()) {
      dfs(dfs, d-1, v1, b^(1LL<<d));
    } else {
      dfs(dfs, d-1, v1, b);
      dfs(dfs, d-1, v2, b^(1LL<<d));
    }
  };
  vector<int> init(n);
  iota(all(init), 0);
  dfs(dfs, 29, init, 0);
  cout << ans << endk;
  return 0;
}
