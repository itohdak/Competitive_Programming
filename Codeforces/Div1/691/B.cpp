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
  int n; cin >> n;
  vector<int> A(n), B(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
    A[i] *= 2;
    B[i] *= 2;
  }
  // int big = 20000;
  int big = accumulate(all(A), 0);
  vector<map<pair<int, int>, int>> dp2(n+1);
  dp2[0][{0, 0}] = 0;
  rep(i, n) for(auto ele: dp2[i]) {
    auto [j, k] = ele.first;
    if(j+1 <= n && k+A[i] <= big) chmax(dp2[i+1][{j+1, k+A[i]}], ele.second+B[i]);
    chmax(dp2[i+1][{j, k}], ele.second+B[i]/2);
  }
  vector<int> ans(n+1);
  for(auto ele: dp2[n]) {
    auto [j, k] = ele.first;
    chmax(ans[j], min(k, ele.second));
  }
  for(int i=1; i<=n; i++) {
    cout << fixed << setprecision(10) << 1.0 * ans[i] / 2 << ' ';
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
