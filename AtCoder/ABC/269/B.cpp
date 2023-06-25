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
  vector<string> S(10);
  rep(i, 10) cin >> S[i];
  int a = 0, b = 0, c = 0, d = 0;
  rep(i, 10) rep(j, 10) {
    if(S[i][j] == '#' && (i == 0 || S[i-1][j] == '.') && (j == 0 || S[i][j-1] == '.')) {
      a = i; c = j;
    }
    if(S[i][j] == '#' && (i == 9 || S[i+1][j] == '.') && (j == 9 || S[i][j+1] == '.')) {
      b = i, d = j;
    }
  }
  cout << a+1 << ' ' << b+1 << endk;
  cout << c+1 << ' ' << d+1 << endk;
  return 0;
}
