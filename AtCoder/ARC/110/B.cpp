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
  string t; cin >> t;
  bool ok1=true, ok2=true, ok3=true;
  string s = "110";
  rep(i, n) {
    if(t[i] != s[i%3]) ok1 = false;
    if(t[i] != s[(i+1)%3]) ok2 = false;
    if(t[i] != s[(i+2)%3]) ok3 = false;
  }
  ll big = 10000000000LL;
  if(t == "1") cout << big * 2 << endk;
  else if(t == "0") cout << big << endk;
  else if(ok1) cout << big - (n-1)/3 << endk;
  else if(ok2) cout << big - n/3 << endk;
  else if(ok3) cout << big - (n+1)/3 << endk;
  else cout << 0 << endk;
  return 0;
}
