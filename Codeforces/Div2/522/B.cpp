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
  string s; cin >> s;
  int n = s.size();
  int r = (n+19)/20;
  int c = (n+r-1)/r;
  int ast = r*c-n;
  vector<string> ans(r);
  int b = 0;
  rep(i, r) {
    if(i < ast-ast/r*r) {
      ans[i] = s.substr(b, c-ast/r-1) + string(ast/r+1, '*');
      b += c-ast/r-1;
    } else {
      ans[i] = s.substr(b, c-ast/r) + string(ast/r, '*');
      b += c-ast/r;
    }
  }
  cout << r << ' ' << c << endk;
  rep(i, r) cout << ans[i] << endk;
  return 0;
}
