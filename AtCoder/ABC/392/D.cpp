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
  vector<int> K(n);
  vector<map<int, int>> A(n);
  rep(i, n) {
    cin >> K[i];
    rep(j, K[i]) {
      int a; cin >> a;
      A[i][a]++;
    }
  }
  ld mx = 0;
  rep(i, n) REP(j, i+1, n) {
    ld tmp = 0;
    for(auto& [a, c]: A[i]) {
      if(A[j].count(a)) {
        tmp += (ld)(1) * c / K[i] * A[j][a] / K[j];
      }
    }
    chmax(mx, tmp);
  }
  cout << fixed << setprecision(10) << mx << endk;
  return 0;
}
