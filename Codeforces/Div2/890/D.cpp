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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<vector<int>> inv(n+1, vector<int>(n+1, -1));
  rep(i, n) {
    inv[i][i] = 0;
    inv[i][i+1] = 0;
  }
  auto query = [&](int l, int r) {
    assert(l <= r);
    if(inv[l][r] == -1) {
      cout << "? " << l+1 << ' ' << r << endl;
      cin >> inv[l][r];
    }
    return inv[l][r];
  };
  auto solve = [&](auto solve, int l, int r) -> int {
    if(r-l <= 1) {
      return l;
    }
    int mid = (l+r)/2;
    int a = solve(solve, l, mid);
    int b = solve(solve, mid, r);
    int q1 = query(a, b);
    int q2 = query(a, b+1);
    if(q1 == q2) {
      return b;
    } else {
      return a;
    }
  };
  int ans = solve(solve, 0, n);
  cout << "! " << ans+1 << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
