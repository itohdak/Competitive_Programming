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

void solve() {
  int n; cin >> n;
  vector<int> P(n);
  vector<int> pos(n+1, -1);
  rep(i, n) {
    cin >> P[i];
    pos[P[i]] = i;
  }
  vector<int> ans;
  auto myswap = [&](int nx) {
    // cout << (int)ans.size() << ' ' << nx << endl;
    // cout << P << endl;
    assert((int)ans.size()%2 == nx%2);
    assert(nx+1 <= n-1);
    assert(nx >= 0);
    ans.push_back(nx);
    swap(pos[P[nx]], pos[P[nx+1]]);
    swap(P[nx], P[nx+1]);
  };
  for(int i=1; i<=n-3; i++) {
    int p = pos[i];
    if((p-1)%2 != (int)ans.size()%2) {
      int nx = -1;
      if(p == n-2) nx = n-4;
      else if(p == n-3) nx = n-5;
      else nx = ((n-2)%2 == (int)ans.size()%2 ? n-2 : n-3);
      myswap(nx);
    }
    while(p > i-1) {
      int nx = p-1;
      myswap(nx);
      p--;
    }
  }
  auto check = [&](int a, int b, int c) {
    return (a < b) && (b < c);
  };
  while(!check(P[n-3], P[n-2], P[n-1])) {
    int nx = ((n-2)%2 == (int)ans.size()%2 ? n-2 : n-3);
    myswap(nx);
  }
  assert(ans.size() <= n*n);
  cout << ans.size() << endk;
  for(int a: ans) cout << a+1 << ' ';
  cout << endk;
  // cout << P << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
