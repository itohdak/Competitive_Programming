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
  vector<string> S(3); rep(i, 3) cin >> S[i];
  vector<bool> exists(4);
  rep(i, 3) {
    exists[(S[i].front()-'0') * 2 + (S[i].back()-'0')] = true;
  }
  if(!exists[0]) {
    cout << string(n, '0') + "1" + string(n, '0') << endk;
  } else if(!exists[3]) {
    cout << string(n, '1') + "0" + string(n, '1') << endk;
  } else if(!exists[1]) {
    
  } else if(!exists[2]) {

  } else {
    assert(false);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(_, t) solve();
  return 0;
}
