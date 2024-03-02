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
  vector<int> V(3); rep(i, 3) cin >> V[i];
  bool found = false;
  vector<int> A(3, -1), B(3, -1), C(3, -1);
  auto vol2 = [](int a1, int b1, int c1, int a2, int b2, int c2) -> int {
    return max(0, min(a1, a2)+7-max(a1, a2)) * max(0, min(b1, b2)+7-max(b1, b2)) * max(0, min(c1, c2)+7-max(c1, c2));
  };
  auto dfs = [&](auto dfs, int cur) -> void {
    if(cur == 3) {
      vector<int> v(3);
      v[2] = max(0, *min_element(all(A))+7-*max_element(all(A))) * max(0, *min_element(all(B))+7-*max_element(all(B))) * max(0, *min_element(all(C))+7-*max_element(all(C)));
      v[1] = vol2(A[0], B[0], C[0], A[1], B[1], C[1]) + vol2(A[0], B[0], C[0], A[2], B[2], C[2]) + vol2(A[1], B[1], C[1], A[2], B[2], C[2]) - 3*v[2];
      v[0] = 3*7*7*7 - 2*v[1] - 3*v[2];
      bool ok = true;
      rep(i, 3) if(v[i] != V[i]) ok = false;
      if(ok) found = true;
      return;
    }
    for(int a=-7; a<=7; a++) {
      for(int b=-7; b<=7; b++) {
        for(int c=-7; c<=7; c++) {
          A[cur] = a, B[cur] = b, C[cur] = c;
          dfs(dfs, cur+1);
          if(found) return;
          A[cur] = -1, B[cur] = -1, C[cur] = -1;
        }
      }
    }
  };
  A[0] = 0, B[0] = 0, C[0] = 0;
  dfs(dfs, 1);
  if(found) {
    cout << "Yes" << endk;
    rep(i, 3) {
      cout << A[i] << ' ' << B[i] << ' ' << C[i] << ' ';
    }
    cout << endk;
  } else {
    cout << "No" << endk;
  }
  return 0;
}
