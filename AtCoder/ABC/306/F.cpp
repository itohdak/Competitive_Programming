#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

int op(int a, int b) {
  return a + b;
}
int e() {
  return 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  vector<int> ALL;
  rep(i, n) {
    rep(j, m) {
      cin >> A[i][j];
      ALL.push_back(A[i][j]);
    }
    sort(all(A[i]));
  }
  ALL.push_back(0);
  sort(all(ALL));
  auto id = [&](int a) {
    return lower_bound(all(ALL), a) - begin(ALL);
  };
  segtree<int, op, e> seg(n*m+1);
  ll ans = 0;
  rrep(i, n) {
    ans += 1LL * (1+m) * m / 2 * (n-i-1);
    rep(j, m) {
      ans += 1LL * (m-j) * seg.prod(id(j==0 ? 0 : A[i][j-1]), id(A[i][j]));
    }
    rep(j, m) {
      seg.set(id(A[i][j]), 1);
    }
  }
  cout << ans << endk;
  return 0;
}
