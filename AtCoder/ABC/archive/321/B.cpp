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
  int n, x; cin >> n >> x;
  vector<int> A(n-1); rep(i, n-1) cin >> A[i];
  sort(all(A));
  int sum = accumulate(all(A), 0);
  int mn = sum - A[n-2];
  int mx = sum - A[0];
  if(mn >= x) {
    cout << 0 << endk;
  } else if(mx < x) {
    cout << -1 << endk;
  } else {
    cout << x - (sum - A[0] - A[n-2]) << endk;
  }
  return 0;
}
