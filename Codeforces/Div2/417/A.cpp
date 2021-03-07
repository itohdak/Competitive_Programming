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
  vector<vector<int>> L(4, vector<int>(4));
  rep(i, 4) rep(j, 4) cin >> L[i][j];
  rep(i, 4) {
    if(L[i][3] && (L[i][0] || L[i][1] || L[i][2] || L[(i+1)%4][0] || L[(i+2)%4][1] || L[(i+3)%4][2])) {
      cout << "YES" << endk;
      return 0;
    }
  }
  cout << "NO" << endk;
  return 0;
}
