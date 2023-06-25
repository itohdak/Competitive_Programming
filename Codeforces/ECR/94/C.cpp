#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  string s; cin >> s;
  int x; cin >> x;
  int n = s.size();
  string w(n, '0');
  rep(i, n) {
    if((i-x<0 || s[i-x]=='1') && (i+x>=n || s[i+x]=='1')) w[i] = '1';
    else w[i] = '0';
  }
  string ss(n, '0');
  rep(i, n) {
    if((i-x<0 || w[i-x]=='0') && (i+x>=n || w[i+x]=='0')) ss[i] = '0';
    else ss[i] = '1';
  }
  if(ss != s) cout << -1 << endk;
  else cout << w << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
