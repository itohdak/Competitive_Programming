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
  vector<vector<int>> B(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> B[i][j];
  bool ok = true;
  rep(i, n) rep(j, m-1) {
    if(B[i][j+1]-B[i][j] != 1) ok = false;
    if((B[i][j+1]-1)%7 < (B[i][j]-1)%7) ok = false;
  }
  rep(j, m) rep(i, n-1) if(B[i+1][j]-B[i][j] != 7) ok = false;
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}