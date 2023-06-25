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
  string s, t; cin >> s >> t;
  string trev = t;
  reverse(all(trev));
  int n = s.size(), n2 = t.size();
  rep(i, n) REP(j, i, n) {
    int l1 = j-i+1, l2 = n2-l1;
    int k = j-l2;
    if(k < 0) continue;
    if(l1 < 0 || l2 < 0) continue;
    if(s.substr(i, l1) == t.substr(0, l1) &&
       s.substr(k, l2) == trev.substr(0, l2)) {
      // cout << i << ' ' << j << ' ' << k << endk;
      // cout << s.substr(i, l1) << endk;
      // cout << t.substr(0, l1) << endk;
      // cout << s.substr(k, l2) << endk;
      // cout << trev.substr(0, l2) << endk;
      cout << "YES" << endk;
      return;
    }
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
