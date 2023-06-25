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
  int n, m; cin >> n >> m;
  vector<int> A(m), B(m);
  vector<vector<int>> candies(n);
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    candies[A[i]].push_back((B[i]+n-A[i])%n);
  }
  vector<ll> maxCost(n);
  rep(i, n) {
    sort(all(candies[i]), greater<int>());
    rep(j, candies[i].size()) {
      chmax(maxCost[i], j*n+candies[i][j]);
    }
  }
  rep(i, n) {
    ll ans = 0;
    rep(j, n) {
      if(candies[j].size()) {
        chmax(ans, (j+n-i)%n+maxCost[j]);
      }
    }
    cout << ans << ' ';
  }
  cout << endk;
  return 0;
}
