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
  int x, y; cin >> x >> y;
  int n; cin >> n;
  vector<pair<int, int>> P(n);
  for(auto& [x, y]: P) cin >> x >> y;
  ld ans = inf;
  rep(i, n) {
    auto [x1, y1] = P[i];
    auto [x2, y2] = P[(i+1)%n];
    // (x2-x1)*(y-y1) = (y2-y1)*(x-x1)
    // (y2-y1)*x - (x2-x1)*y + (y1*(x2-x1)-x1*(y2-y1)) = 0
    chmin(ans, abs((y2-y1)*x - (x2-x1)*y + (y1*(x2-x1)-x1*(y2-y1))) / sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)));
  }
  cout << fixed << setprecision(10) << ans << endk;
  return 0;
}
