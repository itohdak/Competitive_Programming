#include <bits/stdc++.h>
#include <print.hpp>
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
  string s1, s2; cin >> s1 >> s2;
  int h1 = 10*(s1[0]-'0')+(s1[1]-'0');
  int m1 = 10*(s1[3]-'0')+(s1[4]-'0');
  int h2 = 10*(s2[0]-'0')+(s2[1]-'0');
  int m2 = 10*(s2[3]-'0')+(s2[4]-'0');
  int t = h2*60+m2-(h1*60+m1);
  int m = h1*60+m1+t/2;
  printf("%02d:%02d\n", m/60, m%60);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
