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
  int n; cin >> n;
  string s; cin >> s;
  assert(n % 3 == 0);
  vector<vector<int>> pos(3);
  rep(i, n) {
    pos[s[i]-'0'].push_back(i);
  }
  if((int)pos[2].size() > n/3) {
    if((int)pos[1].size() > n/3) {
      if((int)pos[0].size() > n/3) {
        assert(false);
      } else {
        rep(i, pos[2].size()-n/3) s[pos[2][i]] = '0';
        rep(i, pos[1].size()-n/3) s[pos[1][i]] = '0';
      }
    } else {
      if((int)pos[0].size() > n/3) {
        rep(i, pos[2].size()-n/3) s[pos[2][i]] = '1';
        REP(i, n/3, pos[0].size()) s[pos[0][i]] = '1';
      } else {
        rep(i, pos[2].size()-n/3) {
          if(i < n/3-(int)pos[0].size()) s[pos[2][i]] = '0';
          else s[pos[2][i]] = '1';
        }
      }
    }
  } else {
    if((int)pos[1].size() > n/3) {
      if((int)pos[0].size() > n/3) {
        REP(i, n/3, pos[0].size()) s[pos[0][i]] = '2';
        REP(i, n/3, pos[1].size()) s[pos[1][i]] = '2';
      } else {
        rep(i, n/3-(int)pos[0].size()) s[pos[1][i]] = '0';
        rep(i, n/3-(int)pos[2].size()) s[pos[1][pos[1].size()-1-i]] = '2';
      }
    } else {
      if((int)pos[0].size() > n/3) {
        REP(i, n/3, pos[0].size()) {
          if(i-n/3 < n/3-(int)pos[1].size()) s[pos[0][i]] = '1';
          else s[pos[0][i]] = '2';
        }
      } else {
        // assert(false);
      }
    }
  }
  cout << s << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
