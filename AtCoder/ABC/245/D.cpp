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
  vector<int> A(n+1); rep(i, n+1) cin >> A[i];
  vector<int> C(n+m+1); rep(i, n+m+1) cin >> C[i];
  vector<int> B(m+1);
  rrep(i, m+1) {
    int tmp = C[n+i];
    REP(j, i+1, m+1) {
      if(n+i-j < n+1 && n+i-j >= 0) {
        tmp -= A[n+i-j] * B[j];
      }
    }
    assert(tmp % A[n] == 0);
    B[i] = tmp / A[n];
  }
  rep(i, m+1) cout << B[i] << ' ';
  cout << endk;
  return 0;
}
